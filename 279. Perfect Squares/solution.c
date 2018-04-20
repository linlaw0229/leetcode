/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

class Solution {
public:
    int numSquares(int n) {
        if(n <=0) return 0;
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0;
        for(int i= 0; i*i<=n; ++i)  //把可用平方數解決的先設定好
            dp[i*i] = 1;
        
        for(int i= 1; i<= n; ++i){    //选定第一个数为 i  
            for(int j=1; i+j*j<=n; ++j){    //选定另一个数为 j*j  
                dp[i+j*j] = min(dp[i]+1, dp[i+j*j]);
            }
        }
        return dp[n];
    }
};
