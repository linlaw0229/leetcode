/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res; 
        unordered_set<string> dict(wordList.begin(), wordList.end()); //for lookup if the changed word in dictionary or not
        vector<string> p{beginWord}; 
        queue<vector<string>> paths;
        
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        
        while (!paths.empty()) {
            auto t = paths.front(); //start with beginWord
            paths.pop();
            
            if (t.size() > level) {
                for (string w : words) dict.erase(w); //to remove the word that already used on level 1
                words.clear();
                level = t.size();
                if (level > minLevel) break;
            }
            string last = t.back(); //last element of curent path, try to find next word to link
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!dict.count(newLast)) continue; 
                    
                    //can find another word after changing one character in dictionary
                    words.insert(newLast); //put it into set, so we won't use it again
                    
                    /*
                    example: 
                    t: abc->abd->acd
                    newPath= abc->abd->acd + acc
                    */
                    vector<string> nextPath = t; 
                    nextPath.push_back(newLast);
                    
                    
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } 
                    else paths.push(nextPath);
                }
            }
        }
        return res;
    }
};