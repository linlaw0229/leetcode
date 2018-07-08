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
        //array: s, s+1, s+2....e-2, e-1, e
        //if s ==e, means only one number in the array, pick it
        //max(nums[s]- canWin(nums, s+1, e, dp): player1 choose s, player2 will choose between s+1 and e
        //max(nums[e]- canWin(nums, s, e-1, dp): player1 choose e, player2 will choose between s and e-1
        //the reason to deduct is because we need to know whether if player1's choice is greater than player 2
        }
        return dp[s][e];
    }
};