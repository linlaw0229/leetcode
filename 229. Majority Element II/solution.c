/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num0 = 0, num1 = 1, count0 = 0, count1 = 0;
        
        for (auto x: nums) {
            //find two majority element
          if (x == num0) count0++;
          else if (x == num1) count1++;
          else if (! count0) num0 = x, count0 = 1;
          else if (! count1) num1 = x, count1 = 1;
          else count0--, count1--;
        }
        
        //set to zero is because only need to count these two element
        count0 = count1 = 0;
        
        for (auto x: nums)
          if (x == num0) count0++;
          else if (x == num1) count1++;
        vector<int> res;
        if (count0 > nums.size()/3) res.push_back(num0);
        if (count1 > nums.size()/3) res.push_back(num1);
        return res;
        //https://goo.gl/jMTMc9
    }
};