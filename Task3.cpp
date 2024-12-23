#include <iostream>
#include <vector>
using namespace std;

// Function to display the current game board
void showBoard(const vector<vector<char>>& TicTac) {
    cout << "\n";
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << TicTac[row][col];
            if (col < 2) cout << " | ";
        }
        cout << "\n";
        if (row < 2) cout << "--|---|--\n";
    }
    cout << "\n";
}

// Function to verify if a player has won the game
bool isWinner(const vector<vector<char>>& TicTac, char symbol) {
    for (int i = 0; i < 3; i++) {
        if (TicTac[i][0] == symbol && TicTac[i][1] == symbol && TicTac[i][2] == symbol) return true; // Check rows
        if (TicTac[0][i] == symbol && TicTac[1][i] == symbol && TicTac[2][i] == symbol) return true; // Check columns
    }
    if (TicTac[0][0] == symbol && TicTac[1][1] == symbol && TicTac[2][2] == symbol) return true; // Main diagonal
    if (TicTac[0][2] == symbol && TicTac[1][1] == symbol && TicTac[2][0] == symbol) return true; // Opposite diagonal
    return false;
}

// Function to determine if the game ended in a draw
bool isDraw(const vector<vector<char>>& TicTac) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (TicTac[row][col] == ' ') return false;
        }
    }
    return true;
}

int main() {
    char replayOption;
    do {
        vector<vector<char>> TicTac(3, vector<char>(3, ' '));
        char currentSymbol = 'X';
        bool winnerDeclared = false;

        cout << "Welcome to the Tic-Tac-Toe game!\n";

        while (true) {
            showBoard(TicTac);
            int rowChoice, colChoice;

            cout << "Player " << currentSymbol << ", enter your move (row and column: 1-3): ";
            cin >> rowChoice >> colChoice;

            // Input validation
            if (rowChoice < 1 || rowChoice > 3 || colChoice < 1 || colChoice > 3 || TicTac[rowChoice - 1][colChoice - 1] != ' ') {
                cout << "Invalid choice. Please select a valid cell.\n";
                continue;
            }

            // Mark the chosen cell
            TicTac[rowChoice - 1][colChoice - 1] = currentSymbol;

            // Check for win or draw condition
            if (isWinner(TicTac, currentSymbol)) {
                showBoard(TicTac);
                cout << "Congratulations! Player " << currentSymbol << " wins the game!\n";
                winnerDeclared = true;
                break;
            }
            if (isDraw(TicTac)) {
                showBoard(TicTac);
                cout << "It's a draw! No more valid moves left.\n";
                break;
            }

            // Switch the current player
            currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';
        }

        cout << "Would you like to play another game? (y/n): ";
        cin >> replayOption;

    } while (replayOption == 'y' || replayOption == 'Y');

    cout << "Thank you for playing Tic-Tac-Toe! Have a great day!\n";
    return 0;
}
