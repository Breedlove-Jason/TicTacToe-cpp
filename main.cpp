#include <iostream>
#include <array>
#include <random>
#include <limits>

using namespace std;

// Define the size of the game board
const int BOARD_SIZE = 3;

// Define the type for the game board
using BoardType = array<array<char, BOARD_SIZE>, BOARD_SIZE>;

// Initialize random number generator
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 2);

// Function prototypes
void initializeBoard(BoardType &board);

void printBoard(const BoardType &board);

void gameLoop(BoardType &board);

void computerMove(BoardType &board);

bool isValidMove(const BoardType &board, int row, int col);

void makeMove(BoardType &board, char player, int row, int col);

bool isBoardFull(const BoardType &board);

char checkWin(const BoardType &board);

// Main function
int main() {
    // Initialize the game board
    BoardType board;
    initializeBoard(board);

    // Initialize game variables
    bool playerXTurn = true;
    char winner = ' ';

    // Main game loop
    while (!isBoardFull(board) && winner == ' ') {
        printBoard(board);
        if (playerXTurn) {
            cout << "Player X's Turn: " << endl;
            gameLoop(board);
            winner = checkWin(board);
        } else {
            cout << "Player O's Turn: " << endl;
            computerMove(board);
            winner = checkWin(board);
        }
        playerXTurn = !playerXTurn;
    }

    // Print the final game board and the result
    printBoard(board);
    if (winner != ' ') {
        cout << "Game Over! Winner: " << winner << endl;
    } else {
        cout << "Game Over! It's a draw!" << endl;
    }
    return 0;
}

// Function to initialize the game board
void initializeBoard(BoardType &board) {
    for (auto &row: board) {
        row.fill(' ');
    }
}

// Function to print the game board
void printBoard(const BoardType &board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1) {
                cout << " | ";
            }
        }
        if (i < BOARD_SIZE - 1) {
            cout << "\n- - - - -\n";
        }
    }
    cout << "\n";
}

// Function for the game loop for the player
void gameLoop(BoardType &board) {
    int row, col;
    while (true) {
        cout << "Enter a row and column (0 to 2): ";
        if (!(cin >> row) || row < 0 || row >= BOARD_SIZE) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid row. Please enter a number between 0 and 2." << endl;
            continue;
        }
        if (!(cin >> col) || col < 0 || col >= BOARD_SIZE) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid column. Please enter a number between 0 and 2." << endl;
            continue;
        }
        if (isValidMove(board, row, col)) {
            makeMove(board, 'X', row, col);
            break;
        } else {
            cout << "That cell is already taken. Try again." << endl;
        }
    }
}

// Function to check if there is a winner
char checkWin(const BoardType &board) {
    // Check horizontal and vertical lines
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' ';  // No winner yet
}

// Function for the computer to make a move
void computerMove(BoardType &board) {
    while (true) {
        int row = dis(gen), col = dis(gen);
        if (isValidMove(board, row, col)) {
            makeMove(board, 'O', row, col);
            break;
        }
    }
}

// Function to check if a move is valid
bool isValidMove(const BoardType &board, int row, int col) {
    return row >= 0 && col >= 0 && row < BOARD_SIZE && col < BOARD_SIZE && board[row][col] == ' ';
}

// Function to make a move
void makeMove(BoardType &board, char player, int row, int col) {
    board[row][col] = player;
}

// Function to check if the board is full
bool isBoardFull(const BoardType &board) {
    for (const auto &row: board) {
        for (char cell: row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}