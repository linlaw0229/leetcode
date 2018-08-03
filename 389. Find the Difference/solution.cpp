/*
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        //similar to single number, use XOR to find difference between two string
        char res= 0;
        for(auto c: s) res^= c;
        for(auto c: t) res^= c;
        return res;
    }
};