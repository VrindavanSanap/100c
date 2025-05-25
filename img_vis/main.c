#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
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
  char* img_loc = "./bw_imgs/image1.png";
  SDL_Surface* surface  = IMG_Load(img_loc);
  int img_height = surface->h;
  int img_width = surface->w;

  printf("Height = %d \n", img_height);
  printf("Width = %d \n", img_width);
  printf("SDL2 initialized successfully!\n");
  SDL_Quit();
  return 0;
}
