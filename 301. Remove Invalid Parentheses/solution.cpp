/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        /*
        remove extra parentheses
        */
        vector<string> res;
        int i= 0, l= 0, r= 0;
        for(auto c: s){
            if(c == '(')
                l++;
            if(c == ')'){
                if(l == 0) r++;
                else l--;
            }
        }
        
        helper(s, 0, l, r, res);
        return res;
    }
    
    void helper(string s, int start, int cnt1, int cnt2, vector<string>& res) {
        if(cnt1 == 0 && cnt2 == 0){
            if(isValid(s)) res.push_back(s);
            return;
        }
        for(int i= start; i< s.length(); i++){
            //check duplicate
            if(i != start && s[i] == s[i-1]) continue;
            if(cnt1 > 0 && s[i] == '(') 
                helper(s.substr(0, i)+ s.substr(i+1), i, cnt1-1, cnt2, res);
            if(cnt2 > 0 && s[i] == ')')
                helper(s.substr(0, i)+ s.substr(i+1), i, cnt1, cnt2-1, res);
        }
    }
    
    bool isValid(string s){
        int left= 0, right= 0;
        for(auto c: s){
            if(c == '('){
                left++;
            }
            if(c == ')')
                right++;
            
            if(right> left) return false;
        }
        return left == right;
    }
};