/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int high= nums.size()-1, low= 0;
        vector<int> res(2);
        
        //base case
        if(nums.size()== 0)
            return vector<int> {-1, -1};
        
        //search for left side
        while(low< high){
            int mid= low+(high-low)/2;
            if(target> nums[mid])
                low= mid+1;
            else
                high= mid;
        }
        
        res[0] = (target == nums[low])? low: -1;
        
        high= nums.size()-1;
        
        while(low< high){
            int mid= low+(high-low)/2 +1; //notice for the mid value
            if(target>=nums[mid])
                low= mid;
            else
                high= mid-1;
        }
        res[1] = (target == nums[high])? high: -1;
        
        return res;
    }
};