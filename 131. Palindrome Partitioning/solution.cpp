/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        /*
        1. a sub function to check is palindrome or not
        */
        vector<vector<string>> res;
        vector<string> tmp;
        helper(res, tmp, s, 0);
        return res;
    }
    
    void helper(vector<vector<string>>& res, vector<string>& tmp, string s, int start){
        if(start== s.length()){
            res.push_back(tmp);
            return;
        } 
        
        for(int i= start; i< s.length(); i++){
            if(ispalin(s, start, i)){
                tmp.push_back(s.substr(start, i-start+1));
                helper(res, tmp, s, i+1);
                tmp.pop_back();
            }
        }
    }
    
    bool ispalin(string s, int start, int end){
        
        while(start<= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};