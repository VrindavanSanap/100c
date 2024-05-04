#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

char take_user_input() {
  char move;
  cout << "Move: ";
  cin >> move;
  return move;
}

class Board {
 public:
  int board[4][4];
  bool game_over = false;
  int rows = 4;
  int cols = 4;
  Board() {
    memset(board, 0, sizeof(board));  // Initialize all board cells to 0
    place_random_tiles();
  }
  bool gaps_present() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols - 1; j++) {
        if (board[i][j + 1] == 0 && board[i][j] != 0) {
          return true;
        }
      }
    }
  }
  bool shift_left() {
    int end_ptr;
    for (int i = 0; i < rows; i++) {
      // For each row
      end_ptr = 3;
      for (int j = cols - 1; j >= 0; j--) {
        if (board[i][j] != 0) {
          if (end_ptr != j) {
            board[i][end_ptr--] = board[i][j];
            board[i][j] = 0;
          } else {
            end_ptr--;
          }
        }
      }
    }
  }
  bool merge() {
    for (int i = 0; i < rows; i++) {
      for (int j = cols - 1; j > 0; j--) {
        if (board[i][j] == board[i][j - 1] && board[i][j] == board[i][j - 1]!=0) {
          board[i][j] = 2 * board[i][j - 1];
          board[i][j - 1] = 0;
          shift_left();
        }
      }
    }
  }

  void make_move_left() {

      shift_left();
      merge();


    place_random_tiles(1);
  }

  void make_move_right() {
    horizontal_flip();
    make_move_left();
    horizontal_flip();
  }
  void make_move_down() {
    transpose();
    make_move_left();
    transpose();
  }
  void make_move_up() {
    vertical_flip();
    make_move_down();
    vertical_flip();
  }

  void make_move(char move) {
    switch (move) {
      case 'd':
        make_move_left();
        break;
      case 's':
        make_move_down();
        break;
      case 'a':
        make_move_right();
        break;
      case 'w':
        make_move_up();
        break;
      default:
        break;
    }
  }
  void place_random_tiles(int n_tiles = 2) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_coor(0, 3);
    uniform_int_distribution<> dis_prob(0, 9);

    for (int i = 0; i < n_tiles; ++i) {
      int row, col;
      do {
        row = dis_coor(gen);
        col = dis_coor(gen);
      } while (board[row][col] != 0);
      board[row][col] = dis_prob(gen) < 1 ? 4 : 2;
    }
  }

  void print_board() {
    cout << "Board:\n";
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cout << setw(6) << board[i][j] << "|";
      }
      cout << endl;
    }
  }
  void horizontal_flip() {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols / 2;
           ++j) {  // Only iterate up to half the columns to avoid re-swapping
        int temp = board[i][j];
        board[i][j] = board[i][cols - 1 - j];
        board[i][cols - 1 - j] = temp;
      }
    }
  }
  void vertical_flip() {
    transpose();
    horizontal_flip();
    transpose();
  }
  void transpose() {
    for (int i = 0; i < rows; ++i) {
      for (int j = i + 1; j < cols; ++j) {
        // Swap arr[i][j] and arr[j][i]
        int temp = board[i][j];
        board[i][j] = board[j][i];
        board[j][i] = temp;
      }
    }
  }
  void reset() {
    memset(board, 0, sizeof(board));
    place_random_tiles();
  }
};

int main() {
  Board board;
  while (!board.game_over) {
    cout << "2048: 'w'-up 's'-down 'a'-left 'd'-right, 'q'-quit 'r'-reset"
         << endl;
    board.print_board();
    char move;
    while (true) {
      move = take_user_input();
      if (move == 'w' || move == 's' || move == 'a' || move == 'd') {
        break;
      } else if (move == 'r') {
        cout << "Resetting board" << endl;
        board.reset();
        board.print_board();
      } else if (move == 'q') {
        cout << "Bye." << endl;
        return 0;
      } else {
        cout << "Invalid move: " << move << endl;
      }
    }
    board.make_move(move);
  }
  return 0;
}
