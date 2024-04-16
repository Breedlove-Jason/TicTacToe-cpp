#include <iostream>
#include <array>
#include <random>
#include <limits>

using namespace std;

const int BOARD_SIZE = 3;
using BoardType = array<array<char, BOARD_SIZE>, BOARD_SIZE>;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 2);

void initializeBoard(BoardType &board);

void printBoard(const BoardType &board);

void gameLoop(BoardType &board);

void computerMove(BoardType &board);

bool isValidMove(const BoardType &board, int row, int col);

void makeMove(BoardType &board, char player, int row, int col);

bool isBoardFull(const BoardType &board);

int main() {
    BoardType board;
    initializeBoard(board);
    bool playerXTurn = true;

    while (!isBoardFull(board)) {
        printBoard(board);
        if (playerXTurn) {
            cout << "Player X's Turn: " << endl;
            gameLoop(board);
        } else {
            cout << "Player O's Turn: " << endl;
            computerMove(board);
        }
        playerXTurn = !playerXTurn;
    }
    printBoard(board);
    cout << "Game Over!" << endl;
    return 0;
}

void printBoard(const BoardType &board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1) {
                cout << "|";
            }
        }
        if (i < BOARD_SIZE - 1) {
            cout << "\n-+-+-\n";
        }
    }
    cout << "\n";
}

void initializeBoard(BoardType &board) {
    for (auto &row: board) {
        row.fill(' ');
    }
}

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

void computerMove(BoardType &board) {
    while (true) {
        int row = dis(gen), col = dis(gen);
        if (isValidMove(board, row, col)) {
            makeMove(board, 'O', row, col);
            break;
        }
    }
}

bool isValidMove(const BoardType &board, int row, int col) {
    return row >= 0 && col >= 0 && row < BOARD_SIZE && col < BOARD_SIZE && board[row][col] == ' ';
}

void makeMove(BoardType &board, char player, int row, int col) {
    board[row][col] = player;
}

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