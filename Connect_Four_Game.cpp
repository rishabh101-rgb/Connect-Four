#include <iostream>
#include <cstdlib>
#include "Connect_Four_Game.h"
using namespace std;

void Connect_Four_Game::initBoard(int size)
{
  this->SIZE = size;
  this->board = new int*[size];
  for(int i=0; i<size; i++){
    this->board[i] = new int[size];
    for(int j=0; j<size; j++)
      this->board[i][j] = 0;
  }
}

void Connect_Four_Game::showBoard(){

   // Print the Connect4 board
   for (int r = 0; r < SIZE; r++){
      // Draw dashed line
      cout << "+";
      for (int c = 0; c < SIZE; c++)
         cout << "---+";
      cout << "\n";

      // Draw board contents
      cout << "| ";
      for (int c = 0; c < SIZE; c++)
         cout << board[r][c] << " | ";
      cout << "\n";
    }

   // Draw dashed line
   cout << "+";
   for (int c = 0; c < SIZE; c++)
      cout << "---+";
   cout << "\n";

   // Draw column numbers
   cout << "  ";
   for (int c = 1; c <= SIZE; c++)
      cout << c << "   ";
   cout << "\n\n";

}
void Connect_Four_Game::insertValue(int pos){
  // pos--;
  if(pos < 0 || pos > 6){
    cout << "Invalid Position. Try again.";
    return;
  }
  if(rowsLeft(pos)==-1)
  {
    cout << "Invalid Position. Try again.";
    return;
  }
  this->board[rowsLeft(pos)][pos] = getTurn();
}
void Connect_Four_Game::start(){
  system("cls");
  cout << "\t\t\t************************************\n"
       << "\t\t\t*    Welcome to Connect-4-Game     *\n"
       << "\t\t\t************************************\n";
  showBoard();
  this->turn = PLAYER1;
}
int Connect_Four_Game::getTurn(){
  return this->turn;
}
void Connect_Four_Game::switchTurn(int player){
  if(player == PLAYER1) this->turn = PLAYER2;
  else this->turn = PLAYER1;
}
int Connect_Four_Game::rowsLeft(int pos){
  // pos--;
  int row,flag=0;
  for(row=this->SIZE-1; row>=0; row--)
    if(this->board[row][pos] == 0)
    {
      flag=1;
      break;
    }
    if(flag==0)
      row=-1;
  return row;

}
bool Connect_Four_Game::isWin(int player){
  int i, j, k, lim;
  for(i=0;i<SIZE;i++)
    for(j=0;j<SIZE;j++)
      if(this->board[i][j] == player){
        int count = 0;
        //For rows
        for(k=1;k<4;k++)
        {
          if((j+k) < SIZE && this->board[i][j+k] == player)
            count++;
          else  
              break;
        }

        if(count == 3)  return true;
        // else:
        lim = 3 - count;
        for(k=1;k<=lim;k++)
        {
          if((j-k) >=0 && this->board[i][j-k] == player)
            count++;
          else
            break;
        }
        if(count == 3)  return true;

        //For columns
        count = 0;
        for(k=0;k<4;k++)
          if(((i+k) < SIZE && this->board[i+k][j] == player))
            count++;
        if(count == 4)  return true;

        //For diagnals

        // y=-x direction:
        count = 0;
        for(k=1;k<4;k++)
        {
          if(((i+k) < SIZE && (j+k) < SIZE && this->board[i+k][j+k] == player))
            count++;
          else
            break;
        }
        if(count == 3)  return true;

        lim = 3 - count;
        for(k=1;k<=lim;k++)
        {
          if(((i-k) >= 0 && (j-k) >= 0 && this->board[i-k][j-k] == player))
            count++;
          else
            break;
        }
        if(count == 3)  return true;

        // y = x direction:
        count = 0;
        for(k=1;k<4;k++)
        {
          if((i-k) >= 0 && (j+k) < SIZE && this->board[i-k][j+k] == player)
            count++;
          else
            break;
        }
        if(count == 3)  return true;

        lim = 3 - count;
        for(k=1;k<=lim;k++)
        {
          if(((i+k) < SIZE && (j-k) >= 0 && this->board[i+k][j-k] == player))
            count++;
          else
            break;
        }

        if(count == 3)  return true;
      }
  return false;
}

bool Connect_Four_Game::isBoardFull(){
  for(int i=0; i<this->SIZE; i++)
    for(int j=0; j<this->SIZE; j++)
      if(this->board[i][j] == 0) return false;
  return true;
}
