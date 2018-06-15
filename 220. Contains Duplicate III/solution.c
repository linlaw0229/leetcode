/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //Find abs(nums[i]-nums[j]) <= t
        //abs(i-j) <= k
        
        map<long long, int> m; //map<nums[i], i>
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k){ 
                m.erase(nums[j]); //this is to make sure every (i, j) difference will not exceed k
                j++;
            }
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) 
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};