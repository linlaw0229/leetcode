/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        /*
        idea: the 'O' on the edge would still be 'O', so we can change those to another character, '$'. 
        After that, we change every 'O', those did not changed to '$', to 'X' because they must be surrounding by 'X'.
        */
        if(board.empty()) return;
        
        for(int i= 0; i< board.size(); i++){
            dfs(board, i, 0); //first column
            dfs(board, i, board[0].size()-1); //last column
        }
        for(int j= 0; j< board[0].size(); j++){
            dfs(board, 0, j);
            dfs(board, board.size()-1, j);
        }
        
        for(int i= 0; i< board.size(); i++){
            for(int j= 0; j< board[0].size(); j++){
                if(board[i][j] == 'O') board[i][j]= 'X';
                else if(board[i][j] == '$') board[i][j]= 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r >= board.size() || r< 0 || c >= board[0].size() || c< 0 || board[r][c]!= 'O') return;
        board[r][c]= '$';
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
};