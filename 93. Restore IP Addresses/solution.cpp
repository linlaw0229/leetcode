/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(res, "", s, 0, 0);
        return res;
    }
    
    void helper(vector<string>& res, string IP, string s, int index, int count){
        if(count > 4) return;
        if(count == 4 && index == s.length()) {res.push_back(IP); return;}
        
        for(int i= 1; i<= 3; i++){ //an IP is at least one number and at most three numbers
            if((index+i) > s.length()) break; //don't have enough remaining numbers
            string tmp= s.substr(index, i); 
            if(stoi(tmp) > 255 || (tmp[0] == '0' && tmp.length()> 1)) continue;
            helper(res, IP+tmp+(count==3?"":".") , s, index+i, count+1);
        }
    }
};