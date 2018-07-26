/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        /*
        1. find location, '.', to check 
        2. determine what number can this position use. 
            By checking whether if same row || same column || same box, have this number.
        3. after filling this position, we can pass this board to the recursive and check next '.' to be filled.
        */
        if(board.empty() || board[0].size() == 0) return;
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i= 0; i< board.size(); i++){
            for(int j= 0; j< board[0].size(); j++){
                if(board[i][j]== '.'){ //a location needs to be filled
                    for(char c= '1'; c<= '9'; c++){ //try from 1 through 9
                        if(isValid(board, i, j, c)){ //check if this 'c' can put in the position
                            board[i][j]= c; //put c into the location
                           if(solve(board)) //if this is the solution
                                return true;
                            else
                                board[i][j]= '.'; //go back and try another char
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i= 0; i< 9; i++){
            if(board[i][col] != '.' && board[i][col]== c) return false; //check row by row, found c is already used
            if(board[row][i] != '.' && board[row][i]== c) return false;
            int boxR= 3*(row/3)+ i/3;
            int boxC= 3*(col/3)+ i%3;
            if(board[boxR][boxC] != '.' && board[boxR][boxC]== c) return false;
        }
        return true;
    }
    
};
