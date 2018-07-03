/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
*/
//top-bottom solution
class Solution {
public:
    int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		return solve(dp, 1, n);
	}
 
	int solve(vector<vector<int>> &dp, int L, int R) {
		if (L >= R) return 0;
		if (dp[L][R]) return dp[L][R];
		dp[L][R] = INT_MAX;
        
		for (int i = L; i <= R; i++) {
			dp[L][R] = min(dp[L][R], i + max(solve(dp,L,i-1),solve(dp,i+1,R)));
            
		}
		return dp[L][R];
	}
};