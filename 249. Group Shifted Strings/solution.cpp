/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        /*
        1. find out how to find the pattern for each words, we can calculate the diff between every word
        2. use the diff as key, the same words as value
        */
        unordered_map<string, vector<string>> map;
        for(auto s: strings)
            map[shift(s)].push_back(s);
        
        vector<vector<string>> res;
        for(auto s: map){
            res.push_back(s.second);
        }
        return res;
    }
    
    string shift(string input){
        string res;
        for(int i= 1; i< input.length(); i++){
            int diff= input[i]-input[i-1];
            res+= diff< 0 ? diff+26: diff;
            res+= ',';
        }
        return res;
    }
};