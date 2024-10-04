#include <iostream>
#include <unistd.h> // Include the unistd library for sleep

#include <ncurses.h>

using namespace std;

class snake_game {
public:
  snake_game() {

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE); // Enable function keys and arrow keys
    start_color();        // Start color functionality
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // Define a color pair
  }

  int x = 10;
  int y = 10;
  int dir = 2;

  void display() { 
    clear() ;
    mvprintw(y, x, "0"); 
    refresh(); 
  };

  void update() {
    if (dir == 0) {
      x--;
    }
    if (dir == 1) {
      y--;
    }
    if (dir == 2) {
      x++;
    }
    if (dir == 3) {
      y++;
    }
    x = x % COLS;
    y = y % LINES;
  }
  void change_dir(int dir_){
    if (dir_ <4 && dir_ >=0){
      dir = dir_;
    }
  }

};

int main() {
  snake_game myGame;
  while (true) {
    myGame.display();
    myGame.update();
    usleep(25000);
  }
}
