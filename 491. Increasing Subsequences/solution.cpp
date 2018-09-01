/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        vector<int> tmp;
        dfs(res, nums, tmp, 0);
        return res;
    }
    
    
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, int index){
        if(tmp.size() >= 2) res.push_back(tmp);
        
        unordered_set<int> dict;
        for(int i= index; i< nums.size(); i++){
            if(!tmp.empty() && tmp.back()> nums[i] || dict.count(nums[i])) 
                continue;
            
            tmp.push_back(nums[i]);
            dict.insert(nums[i]);
            dfs(res, nums, tmp, i+1);
            tmp.pop_back();
        }
    }
};
