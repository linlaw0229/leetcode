/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

*/

class Solution {
public:
    bool validPalindrome(string s) {
        int l= 0, r= s.length()-1;
        while(l< r){
            if(s[l] != s[r])
                return isValid(s, l+1, r) || isValid(s, l, r-1);
            l++; r--;
        }
        return true;
    }
    
    bool isValid(string s, int left, int right){
        while(left< right){
            if(s[left] != s[right])
                return false;
            left++; right--;
        }
        return true;
    }
};