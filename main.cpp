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

void computerMove(BoardType &board);

bool isValidMoveX(BoardType &board, int row, int col);

int main() {
    BoardType board;
    initializeBoard(board);
//    printBoard(board);
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
    while(true){
        printBoard(board);
        cout << "Enter a row and column for your move:";
        cin >> row >> col;
        if (isValidMoveX(board, row, col)){
            board[row][col] = 'X';
            break;
        }else{
            cout << "Invalid move. Try again." << endl;
        }
    }

} //end 'X' playerMove

void computerMove(BoardType &board) {
    int row, col;
    cout << "Enter the row and column for your move" << endl;
    cin >> row >> col;
    board[row][col] = 'O';

}//end 'X' playerMove

bool isValidMoveX(BoardType &board, int row, int col) {
    if (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE || board[row][col] != ' ') {
        cout << "Invalid move. Try again." << endl;
        playerMove(board);
        return false;
    } else {
        board[row][col] = 'X';
        return true;
    }
} //end isValidMove