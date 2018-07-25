/*
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

class WordDistance {
public:
    unordered_map<string, vector<int>> map;
    WordDistance(vector<string> words) {
        for(int i= 0; i< words.size(); i++){
            map[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto vec1= map[word1];
        auto vec2= map[word2];
        int res= INT_MAX;
        for(int i= 0, j= 0; i< vec1.size()&& j< vec2.size();){
            int idx1= vec1[i];
            int idx2= vec2[j];
            if(idx1< idx2){
                res= min(res, idx2-idx1);
                i++;
            }
            else{
                res= min(res, idx1-idx2);
                j++;
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */