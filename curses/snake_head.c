#include <ncurses.h>
int mod(int a, int b) {
    return (a % b + b) % b; // Ensure non-negative result
}

int clamp(int value, int min, int max) {
    if (value < min) {
        return min; // Return min if value is less than min
    } else if (value > max) {
        return max; // Return max if value is greater than max
    }
    return value; // Return the value if it's within the range
}

void show_snake_head(int x, int y) {

    char ch = '0';
    mvaddch(y, x, ch);
}
void update_snake_head(int *x, int *y, int dir) {
    /*
      0: left
      1: up
      2: right
      3: down
    */
    int rows, cols;

    // Get the maximum dimensions of the standard screen
    getmaxyx(stdscr, rows, cols);

    if (dir == 0) {
        (*x)--;
    }

    if (dir == 1) {
        (*y)--;
    }

    if (dir == 2) {
        (*x)++;
    }

    if (dir == 3) {
        (*y)++;
    }
    *x = mod((*x), cols);
    *y = mod((*y), rows);
}

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    int x = 0;
    int y = 0;
    printw("Press any key to see it on the screen. Press 'q' to exit.\n");
    refresh();

    int ch;
    int dir;
    while (1) {
        ch = getch();
        if (ch == 'q') {
            break;
        }
        if (ch == KEY_UP) {
            dir = 1;
        } else if (ch == KEY_DOWN) {
            dir = 3;
        } else if (ch == KEY_LEFT) {
            dir = 0;
        } else if (ch == KEY_RIGHT) {
            dir = 2;
        }
        clear();
        move(0, 0);
        printw("(%d, %d) dir-%d \n", x, y, dir);
        printw("This is ncurses!");

        update_snake_head(&x, &y, dir);

        show_snake_head(x, y);
        refresh();
    }

    endwin();
    return 0;
}
