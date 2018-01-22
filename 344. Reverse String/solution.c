/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution {
public:
    string reverseString(string s) {
        string _return;
        for(int i = s.size() -1; i>=0; i--)
            _return+=s[i];
        
        return _return;
    }
};

class Solution {
public:
    string reverseString(string s) {
        int j = s.size()-1, i= 0;
        while(i <=j){
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
