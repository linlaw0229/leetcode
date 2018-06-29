class Solution {
public:
    int numDecodings(string s) {
        int n= s.length();
        if(n == 0) return 0;
        
        vector<int> dp(n+1, 0);
        dp[n]= 1; //if this is empty
        dp[n-1]= (s[n-1] != '0') ? 1:0; //start from last character
        
        for(int i= n-2; i>=0; i--){
            if(s[i] == '0') continue;
            else{
                int tmp= stoi(s.substr(i, 2));
                dp[i]= (tmp <= 26) ? dp[i+1]+dp[i+2]: dp[i+1];
            }
        }
        return dp[0];
    }
};