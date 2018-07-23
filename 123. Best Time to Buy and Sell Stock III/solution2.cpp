//https://www.youtube.com/watch?v=oDhu5uGq_ic&feature=youtu.be
class Solution {
public:
    //transaction: k, days: n
    //O(k*n)
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int transactions= 2;
        vector<vector<int>> dp(transactions+1, vector<int>(prices.size(), 0));
        for(int r= 1; r< dp.size(); r++){
            int maxdiff= -prices[0];
            for(int c= 1; c< dp[0].size(); c++){
                dp[r][c]= max(dp[r][c-1], prices[c]+maxdiff);
                maxdiff= max(maxdiff, dp[r-1][c]-prices[c]);
            }
        }
        return dp[transactions][prices.size()-1];
    }
};