/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> candidates= {1,2,3,4,5,6,7,8,9};
        vector<int> tmp;
        backtrack(candidates, res, tmp, k, n, 0);
        return res;
    }
    
    void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int>& tmp, int k, int remain, int pos){
        if(k ==0 && remain == 0) 
            res.push_back(tmp);
        else{ //tmp.size < k, n still need to fill value
            for(int i = pos; i< candidates.size() && k>0 && remain>0; i++){
                tmp.push_back(candidates[i]);
                backtrack(candidates, res, tmp, k-1, remain- candidates[i], i+1);
                tmp.resize(tmp.size()-1);
            }
        }
    }
};