/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()); //put into unordered_set for efficient search
        if (!dict.count(endWord)) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int l = beginWord.length();
        int step = 0;
        
        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; size--) { 
                string w = q.front(); //pick a word in queue to do the search
                q.pop();
                for (int i = 0; i < l; i++) { //the description stated that the length of each word would be the same
                    char ch = w[i]; //change each character to find if there's a match
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        // Found the solution
                        if (w == endWord) return step + 1;
                        
                        // Not in dict, skip it
                        if (!dict.count(w)) continue;
                        
                        // Remove new word from dict, becasue we can only use each word in dictionary once
                        dict.erase(w);
                        
                        // Add new word into queue
                        q.push(w);                    
                    }
                    w[i] = ch;
                }
            }
        }
        return 0;
    }
};