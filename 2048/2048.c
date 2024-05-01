#include <stdio.h>
#include <stdbool.h>

char take_user_input(){
  char move;
  scanf("%c", &move);
  return move;
}

void print_board(int matrix[][4], int rows, int cols) {

    printf("Matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d |", matrix[i][j]);
        }
        printf("\n");
    }
}


int main(){ 
  int board[4][4];
  for (int i =0;i< 4;i++){
    for (int j =0;j< 4;j++){
      board[i][j] = 0;
    }
  }
  char move = '1';
  printf("Make moves using 'j' for up, 'k' for down, 'h' for left, and 'l' for right.\n");
  while(true){

  }
  print_board(board, 4, 4);

  return 0;
}
