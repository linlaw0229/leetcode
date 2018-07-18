/*
Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.
*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        /*
        discussed into two parts, same length or diff length
        1. same length
            check if only one char is different
        2. diff length
            check if w/o the first one different character, the remain is equal or not.
            Once thing to notice is that, we should use longer string to be the delete character one.
        */
        int m= s.length(), n= t.length();
        if(abs(m-n) > 1) return false;
        if(s.length() == t.length()) return sizeEqual(s, t);
        if(s.length() > t.length()) return sizeDiff(s, t);
        else return sizeDiff(t, s);
    }
    
    bool sizeDiff(string s, string t){
        for(int i= 0, j= 0; i< s.length()&& j< t.length(); i++, j++){
            if(s[i]!= t[j]){
                return s.substr(i+1) == t.substr(j);
            }
        }
        return true;
    }
    
    bool sizeEqual(string s, string t){
        int diff= 0;
        for(int i= 0; i< s.length(); i++){
            if(s[i] != t[i]) diff++;
        }
        return diff==1;
    }
};