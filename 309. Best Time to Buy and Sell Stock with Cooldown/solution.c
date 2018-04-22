/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

//https://goo.gl/NjS9r6

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy(INT_MIN), sell(0), prev_sell(0), prev_buy(0);
        
        for(int price: prices){
            prev_buy = buy;
            buy = max(buy, prev_sell-price);
            prev_sell = sell;
            sell = max(sell, prev_buy+price);
        }
        return sell;
    }
};