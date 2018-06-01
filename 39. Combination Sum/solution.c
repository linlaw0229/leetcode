/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> list;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        backtrack(list, tmp, candidates, target, 0);
        return list;
    }
    
private :
    void backtrack(vector<vector<int>>& list, vector<int>& temp, vector<int>& candidates, int remain, int start){
        if(remain < 0) return; //did not match the target
        else if(remain == 0) list.push_back(temp); //put into the result
        else{
            for(int i = start; i< candidates.size(); i++){
                //search candidate[i] have any combanition
                temp.push_back(candidates[i]); 
                backtrack(list, temp, candidates, remain-candidates[i], i); 
                
                temp.resize(temp.size()-1);
            }
        }
    }

};