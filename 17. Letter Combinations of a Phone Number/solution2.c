class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return vector<string>{};
        
        vector<vector<char>> candidates(2, vector<char>{});
        candidates.push_back(vector<char> {'a', 'b', 'c'});
        candidates.push_back(vector<char> {'d', 'e', 'f'});
        candidates.push_back(vector<char> {'g', 'h', 'i'});
        candidates.push_back(vector<char> {'j', 'k', 'l'});
        candidates.push_back(vector<char> {'m', 'n', 'o'});
        candidates.push_back(vector<char> {'p', 'q', 'r', 's'});
        candidates.push_back(vector<char> {'t', 'u', 'v'});
        candidates.push_back(vector<char> {'w', 'x', 'y', 'z'});
        
        string tmp;
        vector<string> res;
        backtrack(res, tmp, candidates, digits, 0);
        return res;
    }
    void backtrack(vector<string> &res, string &tmp, vector<vector<char>>& candidates, string digits, int pos){
        if(pos==digits.size())
            res.push_back(tmp);
        else
            for(int i=0; i<candidates[digits[pos]-'0'].size(); i++) {
                tmp.push_back(candidates[digits[pos]-'0'][i]);
                backtrack(res, tmp, candidates, digits, pos+1);
                tmp.pop_back();
            }
    }
};