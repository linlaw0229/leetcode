/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res= 0;
        int start= 0;
        for(int i= 0; i< s.length(); i++){
            if(s[i]== '(')
                stk.push(i);
            else{
                // ')'
                if(stk.empty()) start= i+1;
                else{
                    stk.pop();
                    if(stk.empty()){
                        res= max(res, i-start+1);
                    }
                    else{
                        res= max(res, i-stk.top());
                    }
                }
            }
        }
        return res;
    }
};