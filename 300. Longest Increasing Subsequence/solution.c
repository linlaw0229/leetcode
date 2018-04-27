/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        vector<int> dp(nums.size());
        dp[0] = 1;
        
        int maxans = 1;
        
        for(int i = 1; i< dp.size(); ++i){
            int maxval = 0;
            for(int j=0; j<i; ++j){
                if(nums[i]> nums[j])
                    maxval = max(dp[j], maxval);
            }
            dp[i] = maxval +1;
            maxans = max(maxans, dp[i]);
        }
        return maxans;
    }
};
