/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;   
        vector<bool> used(nums.size(), false);
        vector<int> tmp;
        backtrack(res, used, tmp, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<bool> &used, vector<int> tmp, vector<int>& nums, int pos){
        if(pos == nums.size()) {
            res.push_back(tmp);
            return;
        }
        
        for(int i = 0; i< nums.size(); i++){
            if(used[i] == false){
                used[i] = true;
                tmp.push_back(nums[i]);
                backtrack(res, used, tmp, nums, pos+1);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }
};