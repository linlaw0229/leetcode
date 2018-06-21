/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if (n <= 2) return n;
        
        int pre = 0, cur = 1, count = 1; //count: how many duplicates
        while (cur < n) {
            if (nums[pre] == nums[cur] && count == 0) ++cur; //already have duplicate, bypass this `cur`, move to next 
            else {
                if (nums[pre] == nums[cur]) --count; //have 2 duplicates
                else count = 1;
                nums[++pre] = nums[cur++];
            }
        }
        return pre + 1;
    }
};