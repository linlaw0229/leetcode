/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        unordered_map<char, int>::iterator it;
        
        int len= 0, i= -1;
        for(int j=0; j< s.length(); j++){
            it = map.find(s.at(j));
            if(it != map.end())
                i = std::max(it->second,i);
            map[s.at(j)] = j;
            len = std::max(len,(j-i));
        }
        return len;
        
    }
};
