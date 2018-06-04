class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size();
        vector<int> dp(m, 0);
        for(int i= n-1; i>= 0; --i){
            for(int j = m-1; j>= 0; --j){
                if(i == n-1 && j != m-1) dp[j] = grid[i][j]+ dp[j+1];
                else if(i != n-1 && j == m-1) dp[j] = grid[i][j]+ dp[j];
                else if(i != n-1 && j != m-1) dp[j] = grid[i][j] + min(dp[j], dp[j+1]);
                else dp[j] = grid[i][j];
                    
            }
        }
        return dp[0];
    }
};