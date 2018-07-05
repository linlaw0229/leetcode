class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.empty()) return true;
        int n= nums.size();
        if((n % 2 == 0)) return true; //if size is even, player one always win
        
        vector<int> dp(n, 0);
        for(int i= n-1; i>= 0; i--){
            for(int j= i; j< n; j++){
                if(i == j)
                    dp[i] = nums[i];
                else
                    dp[j]= max(nums[i]- dp[j], nums[j]- dp[j-1]);
            }
        }
        
        return dp[n-1] >= 0;
    }
};

//space O(n)