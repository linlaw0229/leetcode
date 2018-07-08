class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n= s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return helper(s, 0, n-1, memo);
    }
        
    int helper(string &s, int start, int end, vector<vector<int>>& memo){
        if(memo[start][end] != -1) return memo[start][end]; //already computed
        if(start> end) return 0; 
        if(start== end) return 1;//one character itself is palindromic
        
        if(s[start] == s[end])
        //if first and last character is the same
        //length of longest palindromic with s[start] and s[end] will increase 2
            memo[start][end]= helper(s, start+1, end-1, memo)+2; 
        else
        //no the same, check other 
            memo[start][end]= max(helper(s, start+1, end, memo), helper(s, start, end-1, memo));
        
        return memo[start][end];
    } 
};