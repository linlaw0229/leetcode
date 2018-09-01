/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []

*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;
        if(s.empty() || words.empty()) return res;
        unordered_map<string, int> map;
        for(string word: words)
            map[word]++;
        
        int n= s.length(), num= words.size(), len= words[0].length();
        
        for(int i= 0; i< n- num*len+1; i++){
            unordered_map<string, int> seen;
            int j= 0;
            for(; j< num; j++){
                string word= s.substr(i+j*len, len);
                if(map.find(word) != map.end()){
                    seen[word]++;
                    if(seen[word]> map[word])
                        break;
                }
                else
                    break;
            }
            if(j == num) res.push_back(i);
        }
        return res;

    }
};
