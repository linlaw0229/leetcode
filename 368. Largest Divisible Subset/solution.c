/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> dp(nums.size(), 0), parent(nums.size(), 0);
        int max= 0;
        int max_idx= 0;
        
        for(int i= nums.size()-1; i>= 0; i--){ 
            //start from largest item 
            //because a new number S can be placed into the set as long as it can divide the smallest number of the set 
            //or is divisible by the largest number of the set
            for(int j= i; j< nums.size(); j++){
                if(nums[j]% nums[i] == 0 && dp[i] < dp[j]+1){
                    dp[i]= dp[j]+1;
                    parent[i]= j; //like a linked list to store the next item of subset
                    if(max< dp[i]){ //if max array size smaller than dp[i], need to update
                        max= dp[i];
                        max_idx= i;
                    }
                }
            }
        }
        
        vector<int> res;
        for(int i= 0; i< max; i++){
            res.push_back(nums[max_idx]);
            max_idx= parent[max_idx];
        }
        return res;
    }
};
