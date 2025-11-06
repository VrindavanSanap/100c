/*
  Created by Vrindavan Sanap
  stopwatch.c
  Simple stopwatch cli built with ncurses
  All rights reserved
*/

#include <ncurses.h>
#include <time.h>
typedef enum {
  RESET_STATE,
  RUNNING_STATE,
  PAUSED_STATE,
} clock_state;

double milis(void) {
  struct timespec ts;

  if (timespec_get(&ts, TIME_UTC) != TIME_UTC) {
    fputs("timespec_get failed!", stderr);
    return 0;
  }
  return 1000000.0 * ts.tv_sec + ts.tv_nsec / 1000;
}

int main() {
  // Initialize ncurses
  initscr();
  cbreak();              // Disable line buffering
  noecho();              // Don't echo pressed keys
  keypad(stdscr, TRUE);  // Enable function keys and arrow keys
  timeout(100);
  refresh();  // Refresh to show the initial message
  int ch;
  clock_state current_state;
  current_state = RESET_STATE;
  while (1) {
    // Check for 'q' key to quit
    if (ch == 'q') {
      break;
    }

    if (current_state == RESET_STATE) {
      printw("Press S to start the stopwatch \n");
      if (ch == 's') {
        current_state = RUNNING_STATE;
        clear();
        printw("You started the stopwatch! \n", ch);
      }
    } else if (current_state == RUNNING_STATE) {
      printw("Clock is running! \n");
      printw("Press R to reset the stopwatch \n");
      printw("Press P to pause the stopwatch \n");
      printw("%.0f", milis() / 1000000);
      if (ch == 'r') {
        current_state = RESET_STATE;
        clear();
        printw("You've reset the stopwatch! \n");
      } else if (ch == 'p') {
        current_state = PAUSED_STATE;
        clear();
        printw("You've paused the stopwatch! \n");
      }
    } else if (current_state == PAUSED_STATE) {
      printw("Clock is paused! \n");
      printw("Press R to reset the stopwatch \n");
      printw("Press P to resume the stopwatch \n");
      if (ch == 'r') {
        current_state = RESET_STATE;
      } else if (ch == 'p') {
        current_state = RUNNING_STATE;
      }
    }

    ch = getch();  // Get keyboard input
    clear();
    refresh();  // Refresh to show the output
  }

  // Clean up and exit ncurses
  endwin();
  return 0;
}
