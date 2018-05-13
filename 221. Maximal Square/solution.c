/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = m>0 ? matrix[0].size(): 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int maxlen = 0;
        
        for(int i = 1; i<= m; ++i){
            for(int j= 1; j<= n; ++j){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) +1;
                    maxlen = max(maxlen, dp[i][j]);
                }
            }
        }
        return maxlen*maxlen;
    }
};