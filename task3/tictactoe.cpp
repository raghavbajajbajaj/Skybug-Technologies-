#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // Empty cell found, game not a draw
            }
        }
    }
    return true; // All cells filled, game is a draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize a 3x3 board with empty cells
    char currentPlayer = 'X'; // Start with player 'X'

    do {
        // Display the current state of the board
        cout << "Current Board:" << endl;
        displayBoard(board);

        // Player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the chosen cell is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    return 0;
}
