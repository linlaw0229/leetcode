class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); //-1 means player1 smaller than player2
        return canWin(nums, 0, n - 1, dp) >= 0; 
    }
    int canWin(vector<int>& nums, int s, int e, vector<vector<int>>& dp) {
        if (dp[s][e] == -1) {
            dp[s][e] = (s == e) ? nums[s] : max(nums[s]- canWin(nums, s+1, e, dp), nums[e]- canWin(nums, s, e-1, dp));
        }
        return dp[s][e];
    }
};