#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>> &board)
{
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i)
    {
        cout << "| ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>> &board, char player)
{
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        { // Column
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false; // Board is not full, so not a draw
            }
        }
    }
    return true; // All cells are filled
}

// Function to handle a player's turn
bool makeMove(vector<vector<char>> &board, int row, int col, char player)
{
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
    {
        board[row][col] = player;
        return true;
    }
    return false; // Invalid move (either out of bounds or cell already occupied)
}

int main()
{
    char playAgain;
    do
    {
        // Initialize the board with empty spaces
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver)
        {
            // Display the current board
            displayBoard(board);

            // Ask the current player for their move
            int row, col;
            cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
            cin >> row >> col;

            // Try to make the move
            if (makeMove(board, row, col, currentPlayer))
            {
                // Check for a win
                if (checkWin(board, currentPlayer))
                {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                }
                // Check for a draw
                else if (checkDraw(board))
                {
                    displayBoard(board);
                    cout << "It's a draw!\n";
                    gameOver = true;
                }
                // Switch to the other player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            else
            {
                // Invalid move, prompt the user to try again
                cout << "Invalid move! Try again.\n";
            }
        }

        // Ask if players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
