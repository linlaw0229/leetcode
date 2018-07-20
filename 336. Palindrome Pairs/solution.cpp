/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> dict;
        for(int i= 0; i< words.size(); i++)
            dict[words[i]]= i;
        
        for(int i= 0; i< words.size(); i++){
            for(int j= 0; j<= words[i].length(); j++){
                if(ispalin(words[i], j, words[i].length()- 1)){ 
                    //example: adcbcb, last 4 character is palindrome
                    //so we find from 0 to 2, "ad".
                    //check if there's any "da" in the dictionary to make a final palindrome like "adcbcbda"
                    string suffix= words[i].substr(0, j);
                    reverse(suffix.begin(), suffix.end());
                    if(dict.find(suffix) != dict.end() && i!= dict[suffix])
                        result.push_back({i, dict[suffix]});
                }
                if(j > 0 && ispalin(words[i], 0, j - 1)) {
                    //example: cbcbad, first 4 character is palindrome
                    //so we find from 4 to end, "ad".
                    //check if there's any "da" in the dictionary to make a final palindrome like "cbcbadda"
                    string prefix = words[i].substr(j);
                    reverse(prefix.begin(), prefix.end());
                    if(dict.find(prefix) != dict.end() && dict[prefix] != i) {
                        result.push_back({dict[prefix], i});
                    }
                }
            }
        }
        return result;
    }
    
    bool ispalin(string s, int start, int end){
        while(start< end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
