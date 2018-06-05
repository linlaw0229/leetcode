/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, tmp, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int pos){
        res.push_back(tmp); //add every set into the result
        for(int i = pos; i < nums.size(); i++){
            tmp.push_back(nums[i]); //sequentially add every element in the ressult
            backtrack(res, tmp, nums, i+1);
            tmp.resize(tmp.size()-1);
        }
    }
};