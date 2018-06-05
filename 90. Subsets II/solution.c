/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        backtrack(res, tmp, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& tmp, vector<int> nums, int pos){
        res.push_back(tmp);
        for(int i = pos; i< nums.size(); i++){
            if(i > pos && nums[i] == nums[i-1]) continue;
            tmp.push_back(nums[i]);
            backtrack(res, tmp, nums, i+1); //this is the major difference, need to throw in i, instead of pos
            tmp.pop_back());
        }
    }
};