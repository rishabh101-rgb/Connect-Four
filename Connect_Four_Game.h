#ifndef CONNECT_FOUR_GAME_H
#define CONNECT_FOUR_GAME_H
#define BOARD_SIZE 7
#define PLAYER1 1
#define PLAYER2 2
class Connect_Four_Game
{
  int **board, turn, SIZE;
public:
  void initBoard(int);
  void showBoard();
  void start();
  int getTurn();
  void insertValue(int);
  void switchTurn(int);
  int rowsLeft(int);
  bool isWin(int);
  bool isBoardFull();
};
#endif
