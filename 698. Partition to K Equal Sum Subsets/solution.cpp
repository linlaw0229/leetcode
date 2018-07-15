/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum= accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false; //can not form k subsets
        
        vector<bool> visited(nums.size(), false);
        return helper(nums, k, sum/k, 0, 0, visited);
    }
    
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited){
        if(k == 1) return true; //only need to create one subset, current subset can do it
        if(curSum == target) return helper(nums, k-1, target, 0, 0, visited); //achieve target, need to create k-1 more subset
        for(int i= start; i< nums.size(); i++){
            if(visited[i]) continue;
            visited[i]= true;
            if(helper(nums, k, target, i+1, curSum+nums[i], visited)) 
                return true;
            
            visited[i]= false;
        }
        return false;
    }
    
};