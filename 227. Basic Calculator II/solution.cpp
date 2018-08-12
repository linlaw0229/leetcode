/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char sign= '+';
        int res= 0, tmp= 0;
        for(int i= 0; i< s.length(); i++){
            if(isdigit(s[i]))
                tmp= 10*tmp+s[i]-'0';
            if(!isdigit(s[i]) && !isspace(s[i]) || i == s.length()-1){
                if(sign == '-')
                    stk.push(-tmp);
                else if(sign == '+')
                    stk.push(tmp);
                else{
                    int num;
                    if(sign == '*')
                        num= stk.top()*tmp;
                    else
                        num= stk.top()/tmp;
                    stk.pop();
                    stk.push(num);
                }
                sign= s[i];
                tmp= 0;
            }
        }
        while(!stk.empty()){
            res+= stk.top();
            stk.pop();
        }
        return res;
    }
};
