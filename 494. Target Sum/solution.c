/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

//https://goo.gl/Sk9q1F
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.empty()) return 0;
        int sum= 0;
        for(auto n: nums)
            sum+= n;
        if((sum+S)%2 != 0) return 0; //sum+S should be even
        return find(nums, (sum+S)/2); //need to find this
    }
    
    int find(vector<int>& nums, int target){
        vector<int> dp(target+1); //set to the target need to find, update when n in nums is smaller
        dp[0]= 1;
        for(auto n: nums){
            for(int i= target; i>= n; i--){
                dp[i]+= dp[i-n];
            }
        }
        return dp[target];
    }
};