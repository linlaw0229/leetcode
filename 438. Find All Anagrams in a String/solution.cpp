/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.empty()) return {};
        vector<int> res, m(256, 0);
        for(auto c: p)
            m[c]++;
        
        int left= 0, right= 0, count= p.length();
        while(right< s.length()){
            //find a character in s that also appeared in p, then move right pointer and decrease the count
            //if a character is not in p, then the value will be negative
            if(m[s[right++]]-- >= 1) --count; 
            if(count == 0) res.push_back(left); //the starting index of the anagram
            
            /*
            an anagram's size would be the same as p.length()
            therefore, if length is equal, then we should move left pointer toward right 1 step
            if the value of character key in map is greater or equal then 0, it means it's a character in p
            because in previous step we minus 1 for all characters, so if a character in s is exists in p, then the value in map is at least 0
            */
            if(right-left == p.length() && m[s[left++]]++ >= 0) ++count;
        }
        return res;
    }
};
