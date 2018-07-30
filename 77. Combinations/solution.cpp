/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        /*
        use backtracking, when a temp vector<int> have size k, store then backtracking
        another input is start pos.
        */
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, n, k, 1);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& tmp, int n, int k, int start){
        if(k== 0){
            res.push_back(tmp);
            return;
        }
        
        for(int i= start; i<= n; i++){
            tmp.push_back(i);
            helper(res, tmp, n, k-1, i+1);
            tmp.pop_back();
        }
        
    }
};