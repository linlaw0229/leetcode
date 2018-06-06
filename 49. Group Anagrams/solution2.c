class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, multiset<string>> map;
        for(auto s: strs){
            string tmp = strSort(s); 
            
            map[tmp].insert(s);
        }
        
        vector<vector<string>> res;
        for(auto m: map){
            vector<string> tmp(m.second.begin(), m.second.end());
            res.push_back(tmp);
        }
        return res;
    }
    
    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;
        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                t[p++] += j;
        return t;
    } 
};
