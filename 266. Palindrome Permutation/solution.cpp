/*
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true

*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> set;
        for(auto c: s){
            if(set.find(c) == set.end())
                set.insert(c);
            else
                set.erase(c);
        }
        
        return set.size()<=1? true: false;
    }
};