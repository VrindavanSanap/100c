#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
void handle_sigint(int sig) {
  printf("\nCaught SIGINT (Ctrl+C). Exiting gracefully.\n");
  exit(0);
}

void get_term_size(int* rows, int* cols) {
  // returns the number of rows and colums are there interminal
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
    perror("ioctl");
    exit(EXIT_FAILURE);
  }
  *rows = ws.ws_row;
  *cols = ws.ws_col;
}

int get_term_width() {
  // returns the number of rows and colums are there interminal
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
    perror("ioctl");
    exit(EXIT_FAILURE);
  }
  return (int)ws.ws_col;
}
int get_term_height() {
  // returns the number of rows and colums are there interminal
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
    perror("ioctl");
    exit(EXIT_FAILURE);
  }
  return (int)ws.ws_row;
}
void print_image(SDL_Surface* surface) {
  
  printf("\e[1;1H\e[2J");
  int img_height = surface->h;
  int img_width = surface->w;

  SDL_Surface* rgb_surface =
      SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBX8888, 0);
  // SDL_FreeSurface(surface);
  float scale = 1;
  int new_height, new_width;
  float ratio = (float)img_width / (float)img_height;
  char* density_map =
      "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,^`'. ";

  if (((get_term_height() * ratio * 2) < get_term_width())) {
    new_height = get_term_height();
    new_width = new_height * ratio;
    new_width = new_width * 2;

  } else {
    new_width = get_term_width();
    new_height = new_width / ratio;
    new_height = new_height / 2;
  }

  SDL_Surface* resized = SDL_CreateRGBSurfaceWithFormat(
      0, new_width, new_height, rgb_surface->format->BitsPerPixel,
      rgb_surface->format->format);
  SDL_BlitScaled(rgb_surface, NULL, resized, NULL);
  Uint32* pixels = resized->pixels;

  for (int i = 0; i < (new_width * new_height); i++) {
    uint8_t r, g, b;
    SDL_GetRGB(pixels[i], rgb_surface->format, &r, &g, &b);
    float intensity = (float)(0.299 * r + 0.587 * g + 0.114 * b);

    intensity = intensity / 255;
    intensity = intensity * 68;
    uint8_t density_index = 68 - (uint8_t)intensity;
    // printf("%u %c (r: %u g: %u b: %u )\n", i, density_map[density_index], r,
    // g, b);
    char c = density_map[density_index];
    printf("%c", c);
    if ((i + 1) % new_width == 0) {
      printf("\n");
    }
  }
  SDL_FreeSurface(resized);
}
int main(int argc, char* argv[]) {
  signal(SIGINT, handle_sigint);

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }

  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    printf("IMG_Init Error: %s\n", IMG_GetError());
    SDL_Quit();
    return 1;
  }
  char* img_loc = "./images/flower.png";

  SDL_Surface* surface = IMG_Load(img_loc);
  if (!surface) {
    printf("Failed to load image: %s\n", IMG_GetError());
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  print_image(surface);

  int prev_rows, prev_cols;
  int curr_rows, curr_cols;
  get_term_size(&prev_rows, &prev_cols);
  printf("Rows: %d Cols %d \n", prev_rows, prev_cols);
  fflush(stdout);

  while (true) {
    get_term_size(&curr_rows, &curr_cols);
    if (curr_rows != prev_rows || curr_cols != prev_cols) {
      get_term_size(&prev_rows, &prev_cols);
      printf("Rows: %d Cols %d \n", prev_rows, prev_cols);

      print_image(surface);
      fflush(stdout);
    }
  }

  // SDL_Quit();
  return 0;
}
