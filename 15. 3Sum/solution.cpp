/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() <= 2) return res; //edge case check
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; ++i){ //-2 is because last possible 3Sum sequence could be last 3 item, 
                                                //and the center is n-2
            
            if(i>0 && nums[i] == nums[i-1]) //pass duplicate elements
                continue;
            
            int j=i+1, k=nums.size()-1;
            int target = 0-nums[i]; //because the other two elements would make sequence zero
            
            while(j< k){
                if(nums[j]+ nums[k] == target){
                    res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;//skip same element
                    while(j<k && nums[k]==nums[k+1]) k--;//skip same element
                }
                else if(nums[j]+ nums[k]>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        
        return res;

    }
};