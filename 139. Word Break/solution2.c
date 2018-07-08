class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length()+1, 0);
        dp[0]= true;
        
        for(int i= 1; i<= s.length(); i++){
            for(int j= 0; j< i; j++){
                if(dp[j] && dict.find(s.substr(j, i-j))!= dict.end()){
                    dp[i]= true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
