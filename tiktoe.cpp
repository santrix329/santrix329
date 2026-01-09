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

    char board[3][3]; // 3x3 C-style array for the Tic-Tac-Toe board
    char currentPlayer = 'X'; // Player X starts
    bool gameOver = false;
    std::string playerXName, playerOName; // Added to store player names

    // Added: Prompt for player names
    std::cout << "Enter name for Player X: ";
    std::getline(std::cin, playerXName);
    std::cout << "Enter name for Player O: ";
    std::getline(std::cin, playerOName);

    initializeBoard(board); // Set up the board with empty spaces initially

    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "Players take turns marking a spot on the 3x3 grid.\n";
    std::cout << "You will input the row (0-2) and column (0-2) for your move.\n";
    std::cout << "The first player to get three of their marks in a row,\n";
    std::cout << "column, or diagonal wins!\n\n";

    while (!gameOver) {
        clearScreen(); // Clear console before each turn
        displayBoard(board);

        int row, col;
        bool validInput = false;

        // Input loop for valid move (row and column)
        while (!validInput) {
            // Modified to use player names
            std::cout << (currentPlayer == 'X' ? playerXName : playerOName) << ", enter your move (row column, e.g., 0 1): ";
            std::cin >> row >> col;

            // Basic input validation: Check if input is integers and within range
            if (std::cin.fail() || row < 0 || row > 2 || col < 0 || col > 2) {
                std::cout << "Invalid input. Please enter row and column as numbers between 0 and 2.\n";
                std::cin.clear(); // Clear the error flag
                // Clear the input buffer by ignoring remaining characters up to newline
                while (std::cin.get() != '\n'); // Consume characters until newline
                continue; // Ask for input again
            }

            if (isValidMove(board, row, col)) {
                validInput = true;
            } else {
                std::cout << "That spot is already taken or invalid coordinates. Try again.\n";
            }
        }

        makeMove(board, row, col, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            clearScreen();
            displayBoard(board);
            // Modified to use player names
            std::cout << (currentPlayer == 'X' ? playerXName : playerOName) << " wins! Congratulations!\n";
            gameOver = true;
        } else if (checkDraw(board)) {
            clearScreen();
            displayBoard(board);
            std::cout << "It's a draw! Good game!\n";
            gameOver = true;
        } else {
            // Switch player for the next turn
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    std::cout << "\nGame Over. Thanks for playing!\n";

    // Optional: Keep console open until user presses enter
    std::cout << "Press Enter to exit.";
    // Consume any leftover newline from previous input if present
    // Then wait for a fresh newline from user (Enter key)
    std::cin.get(); // Consume potentially leftover newline
    std::cin.get(); // Wait for actual Enter key press

    return 0;
}

// --- Function Definitions ---

// Initializes the board with empty spaces (e.g., ' ')
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' '; // Initialize with spaces to represent empty
        }
    }
}

// Displays the current state of the board
void displayBoard(const char board[3][3]) {
    std::cout << "   0   1   2\n"; // Column headers
    std::cout << "  -------------\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " | " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |\n"; // Row header
        std::cout << "  -------------\n";
    }
    std::cout << std::endl;
}

// Checks if the chosen spot is empty and within range
// (Range check is now more explicit in main's input validation)
bool isValidMove(const char board[3][3], int row, int col) {
    // Already checked row/col 0-2 in main, so this primarily checks if the spot is ' '
    return board[row][col] == ' ';
}

// Places the current player's mark on the board
void makeMove(char board[3][3], int row, int col, char currentPlayerMark) {
    board[row][col] = currentPlayerMark;
}

// Checks if the current player has won
bool checkWin(const char board[3][3], char currentPlayerMark) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayerMark && board[i][1] == currentPlayerMark && board[i][2] == currentPlayerMark) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == currentPlayerMark && board[1][j] == currentPlayerMark && board[2][j] == currentPlayerMark) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayerMark && board[1][1] == currentPlayerMark && board[2][2] == currentPlayerMark) {
        return true; // Top-left to bottom-right
    }
    if (board[0][2] == currentPlayerMark && board[1][1] == currentPlayerMark && board[2][0] == currentPlayerMark) {
        return true; // Top-right to bottom-left
    }

    return false;
}

// Checks if the board is full (a draw)
bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // If any spot is still a space, it's not a draw yet
            if (board[i][j] == ' ') {
                return false; // Found an empty spot
            }
        }
    }
    return true; // No empty spots left, must be a draw
}

// Clears the console screen based on OS
void clearScreen() {
    system("cls");
}