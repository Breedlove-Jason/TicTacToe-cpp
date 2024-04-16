#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <random>

using namespace std;

const int BOARD_SIZE = 3;
using BoardType = array<array<char, BOARD_SIZE>, BOARD_SIZE>;

// set up the random number between 0, 2
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 2);



void initializeBoard(BoardType &board);

void printBoard(BoardType &board);

void playerMove(BoardType &board);

void computerMove(BoardType &board);

bool isValidMoveX(BoardType &board, int row, int col);

int main() {
    // generate random number
    int RAND_NUM = dis(gen);

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
        cout << endl;
        printBoard(board);
        cout << endl;

        cout << "Enter a row: 0 to 2: ";
        cin >> row;
        cout << "Enter the column: 0 to 2: ";
        cin >> col;
        cout << endl;


        if (isValidMoveX(board, row, col)){
            board[row][col] = 'X';
            break;
        }else{
            cout << "Invalid move. Try again." << endl;
        }
    }

} //end 'X' playerMove

void computerMove(BoardType &board) {
    int RAND_NUM = dis(gen);

    board[RAND_NUM][RAND_NUM] = 'O';

}//end 'O' computerMove

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

//bool isValidMoveO(BoardType &board, int row, int col){
//    int RAND_NUM = dis(gen);
//
//}