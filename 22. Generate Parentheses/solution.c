/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        helper("", n, 0);
        return result;
    }

/*  this hepler function insert result strings to "vector<string> result"
	When number of '(' less than "n", can append '(';
	When number of '(' is more than number of ')', can append ')';

	string s : current string;
	int leftpare_need : number of '(' that have not put into "string s";
	int moreleft : number of '(' minus number of ')' in the "string s";
*/

    void helper(string s, int leftpare_need, int moreleft)
    {
        
        if(leftpare_need == 0 && moreleft == 0)
        {
            result.push_back(s);
            return;
        }
        if(leftpare_need > 0)
            helper(s + "(", leftpare_need - 1, moreleft+1);
        if(moreleft > 0)
            helper(s + ")", leftpare_need, moreleft - 1);
    }

};

/* Example:
input n=2
output ()(), (())

( , 1, 1 -> goto next inner loop-> ((, 0, 2 -> ((), 0, 1 -> (()), 0, 0 -> push to result
( , 1, 1 -> goto next helper -> (), 1, 0 -> ()(, 0, 1-> ()(), 0, 0 -> push to result
*/
