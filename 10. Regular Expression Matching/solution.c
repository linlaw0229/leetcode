/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/

class Solution {
public:
    bool isMatch(string input, string pattern) {
        if(!pattern.length()) return !input.length(); 
        //check for end case, pattern and text both empty
        
        bool first_match = (input.length() && 
                            ((pattern[0] == input[0]) || pattern[0] == '.'));
        
        if(pattern.length() >= 2 && pattern[1] == '*'){
            return (isMatch(input, pattern.substr(2)) || 
                    (first_match && isMatch(input.substr(1), pattern))); 
            //checking is because the character ahead of * may repeat 0 times
        }
        else{
            return first_match && isMatch(input.substr(1), pattern.substr(1)); 
        }
        
    }
};