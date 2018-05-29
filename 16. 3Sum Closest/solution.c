/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size() < 3) return 0;
        int closest = nums[0]+nums[1]+nums[2]; //pick a sum value to compare
        sort(nums.begin(), nums.end()); //sort the array, takes O(log n)
        for(int first = 0 ; first < nums.size()-2 ; ++first) {
            if(first > 0 && nums[first] == nums[first-1]) continue; //skip the duplicate items
            int second = first+1; //2nd pointer go toward left
            int third = nums.size()-1; //3rdd pointer go toward right         
            while(second < third) { //use 1st pointer as index, find the set has closest sum
                int curSum = nums[first]+nums[second]+nums[third];
                if(curSum == target) return curSum;
                if(abs(target-curSum)<abs(target-closest)) {
                    closest = curSum;
                }
                if(curSum > target) { //because the array is sorted, we can decide where the pointer should move.
                    --third;
                } else {
                    ++second;
                }
            }
        }
        return closest;
    }
};