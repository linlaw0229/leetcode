/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, multiset<string>> map;
        for(auto s: strs){
            string tmp = s; 
            sort(tmp.begin(), tmp.end());  //use the sorted string as key to store every similar strings
            map[tmp].insert(s);
        }
        
        vector<vector<string>> res;
        for(auto m: map){
            vector<string> tmp(m.second.begin(), m.second.end());
            res.push_back(tmp);
        }
        return res;
    }
};
