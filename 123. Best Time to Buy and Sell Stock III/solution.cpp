/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

class Solution {
public:
    //transaction: k, days: n
    //O(k*n^2)
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int transactions= 2;
        vector<vector<int>> dp(transactions+1, vector<int>(prices.size(), 0));
        for(int r= 1; r< dp.size(); r++){
            for(int c= 1; c< dp[0].size(); c++){
                int maxval= 0;
                for(int m= 0; m< c; m++){
                    maxval= max(maxval, prices[c]-prices[m]+ dp[r-1][m]);
                }
                dp[r][c]= max(dp[r][c-1], maxval);
            }
        }
        return dp[transactions][prices.size()-1];
    }
};