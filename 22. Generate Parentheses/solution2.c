class Solution {
public:
    vector<string> generateParenthesis(int n) { 
        vector<string> res;
        string tmp;
        backtrack(res, tmp, n, 0); 
        return res;
    }
    void backtrack(vector<string> &res, string tmp, int left, int right){
        if(left == 0 && right == 0) {
            res.push_back(tmp);
            return;
        }
        if(right > 0) backtrack(res, tmp+")", left, right-1);
        if(left > 0) backtrack(res, tmp+"(", left-1, right+1);
        
    }
};