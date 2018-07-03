class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res= 0;
        
        //setup the top row
        for(int i= 0; i< matrix.size(); i++){
            if(matrix[i][0] == '1') //the input 2d array is char
                dp[i][0] = 1;
            res= max(res, dp[i][0]);
        }

        //setup for left most column
        for(int j= 0; j< matrix[0].size(); j++){
            if(matrix[0][j] == '1')
                dp[0][j] = 1;
            res= max(res, dp[0][j]);
        }
        
        for(int i= 1; i< matrix.size(); i++){
            for(int j= 1; j< matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                    res= max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }
};