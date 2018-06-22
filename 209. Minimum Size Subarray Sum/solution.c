/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int left= 0, right= 0, sum= 0, res= nums.size() +1;
        while(right< nums.size()){
            
            while(sum< s && right< nums.size()){ //if sum still have quota, and hasn't reach end
                sum+= nums[right++]; //add current value to sum, right move to next position
            }
            
            while(sum >= s){
                res= min(res, right-left);
                sum -= nums[left++];
            }
        }
        return res == nums.size()+1 ? 0: res;
    }
};
