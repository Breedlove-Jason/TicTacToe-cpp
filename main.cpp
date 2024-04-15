#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

const int BOARD_SIZE = 3;
using BoardType = array<array<char, BOARD_SIZE>, BOARD_SIZE>;

void initializeBoard(BoardType &board);

void printBoard(BoardType &board);

void playerMove(BoardType &board);

void computerMove(BoardType& board);

int main() {
    BoardType board;
    initializeBoard(board);
    printBoard(board);
    playerMove(board);
    printBoard(board);
    computerMove(board);
    printBoard(board);

    return 0;
}

void printBoard(BoardType &board) {
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
} //end printBoard

void initializeBoard(BoardType &board) {
    for (auto &row: board) {
        row.fill(' ');
    }
} //end initializeBoard

void playerMove(BoardType &board) {
    int row, col;
    cout << "Enter row and column for your move: ";
    cin >> row >> col;
    board[row][col] = 'X';
} //end playerMove

void computerMove(BoardType& board){
    int row, col;
    cout << "Enter the row and column for your move" << endl;
    cin >> row >> col;
    board[row][col] = 'O';


}