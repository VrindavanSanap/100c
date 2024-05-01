#include <iostream>
using namespace std;


char take_user_input(){
  char move;
  scanf("%c", &move);
  return move;
}


class Board {

  public: 
    int board[4][4];
    bool game_over = false;
    int rows = 4;
    int cols = 4;
    Board() {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          board[i][j] = 0;
         }
      }
    }

    void print_board() {
      printf("Board:\n");
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          cout << " "<< board[i][j] << "|";
        }
        cout << endl;
      }
    }
};

int main(){ 
  Board board;
  while (!board.game_over){
    board.print_board();
    char move = '1';
    cout <<"Make move: 'j' for up, 'k' for down, 'h' for left, and 'l' for right."<<endl;
    while(true){
      move = take_user_input();
      if (move=='j' || move=='k' || move=='h' || move=='l'){
        break;
      } else {
        cout << "Wrong move" <<endl;
      }
    }
  }
  return 0;
}
