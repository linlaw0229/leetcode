/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || !word.length()) return false; //nothing in board || nothing in word
        int rowNum= board.size(), colNum= board[0].size();
        vector<vector<bool>> visited(rowNum, vector<bool>(colNum, false)); //create a visit array to check if visited
        
        for(int i =0; i< rowNum; ++i){
            for(int j= 0; j< colNum; ++j){
                //use [i][j] as start point, search for word
                if(exist(board, visited, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int i, int j, int pos) {
        if(pos == word.length()) return true;
        if( i< 0 || j< 0 || i> board.size()-1 || j>board[0].size()-1) return false; //edge case for size
        if(visited[i][j] || board[i][j] != word.at(pos)) return false; 
        //already came this slot || [i][j] is different from word[pos]
        
        visited[i][j] = true;
        
        //DFS
        if (exist(board, visited, word, i - 1, j, pos + 1) //check toward left
            || exist(board, visited, word, i + 1, j, pos + 1) //check toward right
            || exist(board, visited, word, i, j - 1, pos + 1) //check toward top
            || exist(board, visited, word, i, j + 1, pos + 1)) //check toward bottom
            return true; 
        
        visited[i][j] = false; //this slot can not make a same search word
        return false;
    }
};