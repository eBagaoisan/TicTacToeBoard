#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X){
    turn = O;
    return O;
  }
  else{
    turn = X;
    return X;
  }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  //check if spot is valid
  if(getPiece(row, column) == Invalid){
    return Invalid;
  }

  //check if spot is blank
  else if(board[row][column] == Blank){
    if(turn == X){
      board[row][column] = X;
      if(getWinner() == Invalid){
       toggleTurn();
       return X;
      }
    }
    else{
      board[row][column] = O;
      if(getWinner() == Invalid){
       toggleTurn();
       return O;
      }
    }
  }

  //return piece in spot
  else{
    return getPiece(row, column);
  }
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if((row < BOARDSIZE) && (column < BOARDSIZE)){
    return board[row][column];
  }
  return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  //checking for X
  if(board[1][1] == X){
    if(board[0][0] == X){     //left diagonal
      if(board[2][2] == X){
        return X;
      }
    }
    if(board[0][1] == X){     //middle column
      if(board[2][1] == X){
        return X;
      }
    }
    if(board[1][0] == X){     //middle row
      if(board[1][2] == X){
        return X;
      }
    }
    if(board[0][2] == X){
      if(board[2][0] == X){
        return X;             //right diagonal
      }
    }
  }
  if(board[0][0] == X){       //top-left corner
    if(board[1][0] == X){     //top side
      if(board[2][0] == X){
        return X;
      }
    }
    if(board[0][1] == X){     //left side
      if(board[0][2] == X){
        return X;
      }
    }
  }
  if(board[2][2] == X){       //bottom-right corner
    if(board[2][1] == X){     //right side
      if(board[2][0]){
        return X;
      }
    }
    if(board[1][2] == X){     //bottom side
      if(board[0][2] == X){
        return X;
      }
    }
  }

  //checking for O
  if(board[1][1] == O){
    if(board[0][0] == O){     //left diagonal
      if(board[2][2] == O){
        return O;
      }
    }
    if(board[0][1] == O){     //middle column
      if(board[2][1] == O){
        return O;
      }
    }
    if(board[1][0] == O){     //middle row
      if(board[1][2] == O){
        return O;
      }
    }
    if(board[0][2] == O){     //right diagonal
      if(board[2][0] == O){
        return O;             
      }
    }
  }
  if(board[0][0] == O){       //top-left corner
    if(board[1][0] == O){     //top side
      if(board[2][0] == O){
        return O;
      }
    }
    if(board[0][1] == O){     //left side
      if(board[0][2] == O){
        return O;
      }
    }
  }
  if(board[2][2] == O){       //bottom-right corner
    if(board[2][1] == O){     //right side
      if(board[2][0]){
        return O;
      }
    }
    if(board[1][2] == O){     //bottom side
      if(board[0][2] == O){
        return O;
      }
    }
  }  

  //checking for blank spot
  for(int i = 0; i < BOARDSIZE; i++){
    for(int j = 0; j < BOARDSIZE; j++){
      if(board[i][j] == Blank){
        return Invalid;
      }
    }
  }

  //didn't return any other case, therefore tie
  return Blank;
}
