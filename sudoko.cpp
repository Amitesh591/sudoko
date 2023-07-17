#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, char val) {
        int row = i - i % 3, column = j - j % 3;
        for (int x = 0; x < 9; x++) if (board[x][j] == val) return false;
        for (int y = 0; y < 9; y++) if (board[i][y] == val) return false;
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                if (board[row + x][column + y] == val) return false;
        return true;
    }

    bool solveSudoku(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solveSudoku(board, i + 1, 0);
        if (board[i][j] != '.') return solveSudoku(board, i, j + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solveSudoku(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }

    vector<vector<char>> getSolvedSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
        return board;
    }
};


int main() {
    Solution solver;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    vector<vector<char> > userBoard (9,vector<char>(9,'.'));
    cout<<"Enter board row wise and if element not present enter .";
    for(int i=0;i<9;i++)
    {
        cout<< "Enter row"<<i+1<<endl;
        for(int j=0;j<9;j++)
        {
            cout<< "Enter element no"<<j+1<<endl;
            cin>> userBoard[i][j];
        }
    }

    cout << "Unsolved Sudoku:" << endl;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<char>> solvedBoard = solver.getSolvedSudoku(userBoard);

    cout << "\nSolved Sudoku:" << endl;
    for (int i = 0; i < solvedBoard.size(); i++) {
        for (int j = 0; j < solvedBoard[i].size(); j++) {
            cout << solvedBoard[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
