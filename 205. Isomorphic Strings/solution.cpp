/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {-1}, m2[256] = {-1}, n = s.size();
        //use two int array to denote the latest use of a character's position
        //the index can see as 'a'-'0'
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false; //because we traverse from start to end, the occurrence of that character must be the same
            m1[s[i]] = i; //store the last use of that character
            m2[t[i]] = i;
        }
        return true;
    }
};