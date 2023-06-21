#include <iostream>
#include <string>
#include <algorithm>
#include "Connect_Four_Game.cpp"

using namespace std;

void printLastMsg()
{
  cout << "\t\t\t************************************\n"
       << "\t\t\t*      Thank you for playing       *\n"
       << "\t\t\t************************************\n";
  system("pause");
}
int main()
{
    string ans;
    cout<<"Do you wan to play (y/n):\n";
    cin>>ans;
    transform(ans.begin(), ans.end(), ans.begin(),::tolower);
    while(ans=="y")
    {
    
        Connect_Four_Game *game = new Connect_Four_Game();
        int pos, choice; bool win=false;
        game->initBoard(BOARD_SIZE);
        game->start();
        cout << '\n';
        int i=0;

        while(!(game->isBoardFull() || win))
        {
            cout << "Player:" << game->getTurn() << '\n';
            cout << "Enter Column No (1-7): ";
            cin >> pos;
            pos--;
            if(game->rowsLeft(pos) < 0){
            cout << "Column has filled up. Select any other.\n";
            continue;
            }
            game->insertValue(pos);
            win = game->isWin(game->getTurn());
            system("cls");
            game->showBoard();
            game->switchTurn(game->getTurn());
        }

        if(game->isWin(PLAYER1))
            cout << "\n"
                << "Player 1 has won the game.\n";
        else
            cout << "\n"
                << "Player 2 has won the game.\n";


        cout<<"Do you wan to play (y/n):\n";
        cin>>ans;
        transform(ans.begin(), ans.end(), ans.begin(),::tolower);
        delete game;
    }
    return 0;
}
