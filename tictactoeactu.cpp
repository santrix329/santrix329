#include <iostream> // For input/output operations (cin, cout)
#include <cstdlib>  // Required for system() function (for clearing screen)
#include <string>   // Added for std::string to store player names

// Function prototypes
void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
bool isValidMove(const char board[3][3], int row, int col);
void makeMove(char board[3][3], int row, int col, char currentPlayerMark);
bool checkWin(const char board[3][3], char currentPlayerMark);
bool checkDraw(const char board[3][3]);
void clearScreen(); // Custom function to clear console

int main() {

    char board[3][3];
    char currentPlayer = 'X';
    bool gameOver = false;
    std::string playerXName, playerOName;
    int scoreX = 0;
    int scoreO = 0;

    std::cout << "Enter name for Player X: ";
    std::getline(std::cin, playerXName);
    std::cout << "Enter name for Player O: ";
    std::getline(std::cin, playerOName);

    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "Players take turns marking a spot on the 3x3 grid.\n";
    std::cout << "You will input the row (0-2) and column (0-2) for your move.\n";
    std::cout << "The first player to get three of their marks in a row,\n";
    std::cout << "column, or diagonal wins!\n\n";

    bool keepPlaying = true;

    while (keepPlaying) {
        initializeBoard(board);
        gameOver = false;
        currentPlayer = 'X';

        while (!gameOver) {
            clearScreen();
            std::cout << "Scoreboard:\n";
            std::cout << playerXName << " (X): " << scoreX << " wins\n";
            std::cout << playerOName << " (O): " << scoreO << " wins\n\n";
            displayBoard(board);

            int row, col;
            bool validInput = false;

            while (!validInput) {
                std::cout << (currentPlayer == 'X' ? playerXName : playerOName) << ", enter your move (row column, e.g., 0 1): ";
                std::cin >> row >> col;

                if (std::cin.fail() || row < 0 || row > 2 || col < 0 || col > 2) {
                    std::cout << "Invalid input. Please enter numbers between 0 and 2.\n";
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    continue;
                }

                if (isValidMove(board, row, col)) {
                    validInput = true;
                } else {
                    std::cout << "That spot is already taken. Try again.\n";
                }
            }

            makeMove(board, row, col, currentPlayer);

            if (checkWin(board, currentPlayer)) {
                clearScreen();
                displayBoard(board);
                std::cout << (currentPlayer == 'X' ? playerXName : playerOName) << " wins! Congratulations!\n";
                if (currentPlayer == 'X') scoreX++;
                else scoreO++;
                gameOver = true;
            } else if (checkDraw(board)) {
                clearScreen();
                displayBoard(board);
                std::cout << "It's a draw! Good game!\n";
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        std::cout << "\nDo you want to play another game? (y/n): ";
        char response;
        std::cin >> response;
        if (response != 'y' && response != 'Y') {
            keepPlaying = false;
        }
    }

    std::cout << "\nFinal scores:\n";
    std::cout << playerXName << " (X): " << scoreX << " wins\n";
    std::cout << playerOName << " (O): " << scoreO << " wins\n";
    std::cout << "\nThanks for playing!\n";
    std::cout << "Press Enter to exit.";
    std::cin.get();
    std::cin.get();

    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const char board[3][3]) {
    std::cout << "   0   1   2\n";
    std::cout << "  -------------\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " | " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |\n";
        std::cout << "  -------------\n";
    }
    std::cout << std::endl;
}

bool isValidMove(const char board[3][3], int row, int col) {
    return board[row][col] == ' ';
}

void makeMove(char board[3][3], int row, int col, char currentPlayerMark) {
    board[row][col] = currentPlayerMark;
}

bool checkWin(const char board[3][3], char currentPlayerMark) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayerMark && board[i][1] == currentPlayerMark && board[i][2] == currentPlayerMark) {
            return true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == currentPlayerMark && board[1][j] == currentPlayerMark && board[2][j] == currentPlayerMark) {
            return true;
        }
    }
    if (board[0][0] == currentPlayerMark && board[1][1] == currentPlayerMark && board[2][2] == currentPlayerMark) {
        return true;
    }
    if (board[0][2] == currentPlayerMark && board[1][1] == currentPlayerMark && board[2][0] == currentPlayerMark) {
        return true;
    }
    return false;
}

bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void clearScreen() {
    system("cls");
}

