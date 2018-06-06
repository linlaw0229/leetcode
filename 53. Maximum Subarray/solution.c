/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

https://leetcode.com/problems/maximum-subarray/discuss/20211/Accepted-O(n)-solution-in-java
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum= 0, max= nums[0];
        for(int i = 0; i< nums.size(); i++){
            sum = nums[i] + (sum < 0 ? 0:sum);
            max = sum > max ? sum:max;
        }
        return max;
    }
};




