/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> tmp;
        vector<vector<int>> res;
        backtrack(candidates, tmp, res, target, 0);
        return res;
    }
    
    void backtrack(vector<int>& candidates, vector<int>& tmp, vector<vector<int>>& res, int remain, int pos){
        
        if(remain == 0) res.push_back(tmp);
        else if(remain < 0) return;
        else{
            for(int i = pos; i< candidates.size(); i++){
                //skip duplicate, because the question is asked for unique combination
                if(i > pos && candidates[i] == candidates[i-1]) continue; 
                
                tmp.push_back(candidates[i]);
                backtrack(candidates, tmp, res, remain-candidates[i], i+1);
                tmp.resize(tmp.size()-1);
            }
        }
    }
};