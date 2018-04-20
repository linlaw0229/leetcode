/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto& s = grid;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = n-1; i>=0; --i){
            for(int j = m-1; j>=0; --j){
                if(i == n-1 && j != m-1)    //edge case, last row
                    s[i][j] += s[i][j+1];
                else if(i != n-1 && j == m-1)
                    s[i][j] += s[i+1][j];
                else if(i != n-1 && j != m-1)
                    s[i][j] = s[i][j] + min(s[i][j+1], s[i+1][j]);
            }          
        }
        return s[0][0];
    }    
};