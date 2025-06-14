#include <ncurses.h>
/*
  code showcasing continous input
  in c programing langauge
*/

int main() {
  // Initialize ncurses
  initscr();
  cbreak();              // Disable line buffering
  noecho();              // Don't echo pressed keys
  keypad(stdscr, TRUE);  // Enable function keys and arrow keys

  printw("Press any key to see it on the screen. Press 'q' to exit.\n");
  refresh();  // Refresh to show the initial message

  int ch;
  while (1) {
    ch = getch();  // Get keyboard input
    // Check for 'q' key to quit
    if (ch == 'q') {
      break;
    }
    // Print the character to the screen
    printw("You pressed: '%c'\n", ch);
    refresh();  // Refresh to show the output
  }

  // Clean up and exit ncurses
  endwin();
  return 0;
}
