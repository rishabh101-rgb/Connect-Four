# Connect Four Game - C++ Implementation

This is a **Connect Four** game implemented in C++ where two players take turns to place their discs on a 7x7 grid. The goal of the game is to connect four of your own discs in a row, either horizontally, vertically, or diagonally. The game ends when one player wins or the board is full, resulting in a draw.

## Features

- **Game Board**: A 7x7 grid.
- **Two-Player Mode**: Players alternate turns.
- **Win Condition**: First player to connect four discs in a row (horizontally, vertically, or diagonally) wins.
- **Invalid Moves**: The game checks for invalid moves, such as trying to place a disc in a full column.
- **Restart Option**: After each game, players are prompted to play again.

## Files

- **ConnectFourGame.cpp**: Contains the main game logic, including board initialization, player turns, win-checking, and displaying the board.
- **ConnectFourGame.h**: Header file for the `Connect_Four_Game` class, which defines methods to manage game operations.
- **main.cpp**: The entry point for the program where the game loop is executed, prompting players for input and restarting the game after it finishes.

## How to Play

1. The game board is displayed in the console, with each player taking turns.
2. Players input the column number (1-7) to place their disc. The discs fall to the lowest available row in the column.
3. The game checks if the current player has achieved a winning condition after every turn.
4. The game continues until a player wins or the board is full.
5. After the game ends, players are asked if they want to play again.

## How to Run

### Prerequisites

- **C++ Compiler** (e.g., GCC, MinGW, or any C++ IDE)

### Steps

1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/your-username/connect-four-game.git
    ```
2. Navigate to the project directory:
    ```bash
    cd connect-four-game
    ```
3. Compile the code using a C++ compiler. For example:
    ```bash
    g++ main.cpp ConnectFourGame.cpp -o connect_four_game
    ```
4. Run the executable:
    ```bash
    ./connect_four_game
    ```

### Game Commands
- Enter a number between **1 to 7** to choose the column where you want to place your disc.

## Example Gameplay

```
Do you want to play (y/n):
y

+---+---+---+---+---+---+---+
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
+---+---+---+---+---+---+---+
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
+---+---+---+---+---+---+---+
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
+---+---+---+---+---+---+---+
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
+---+---+---+---+---+---+---+
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
+---+---+---+---+---+---+---+
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
+---+---+---+---+---+---+---+
  1   2   3   4   5   6   7

Player: 1
Enter Column No (1-7): 3
```
