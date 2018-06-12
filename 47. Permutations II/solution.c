/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        backtrack(res, tmp, used, nums);
        return res;
    }
    
    void backtrack(vector<vector<int>> &res, vector<int> tmp, vector<int>& used, vector<int>& nums){
        if(tmp.size() == nums.size()){
            res.push_back(tmp);
            return;
        }
        
        for(int i = 0; i< nums.size(); i++){
            if(used[i]) continue; //this element has been chosen
            if(i>0 && nums[i] == nums[i-1] && !used[i-1] ) continue; //previous identical element has been selected
            
            used[i] = true;
            tmp.push_back(nums[i]);
            backtrack(res, tmp, used, nums);
            tmp.pop_back();
            used[i] = false;
        }
    }
};