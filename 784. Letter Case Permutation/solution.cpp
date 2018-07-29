/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.
*/

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        /*
        1. use toupper and tolower function in c++
        2. backtracking function(int start, res, string)
        3. for every character in S, determine if it's number or letter
        4. backtrack the string
        */
        vector<string> res;
        helper(res, S, 0);
        return res;
    }
    
    void helper(vector<string>& res, string& s, int pos){
        if(pos == s.length()){
            res.push_back(s);
            return;
        }
        char c= s[pos]; //initial character
        
        if(isdigit(c)) {
            helper(res, s, pos+1);
            return;
        }
        else{
            helper(res, s, pos+1);
            if(isupper(c)){ //1A
                s[pos]= tolower(s[pos]); //change to 1a
            }
            else{ //1a
                s[pos]= toupper(s[pos]); //change to 1A
            }
            helper(res, s, pos+1);
        }
    }
};