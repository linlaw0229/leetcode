class Solution { 
public:
    int minDistance(string word1, string word2) { 
        int m = word1.length(), n= word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        //convert word2 to word1 if word2 is empty, so the operation is m times
        //ex: word1: "ABCDE", word2= ""  
        //notice: start from 1 because dp[i][j] denotes word1[0...i-1] are the same as word2[0...j-1]
        for(int i= 1; i<= m; ++i)
            dp[i][0] = i;
        
        //convert word1 to word2 if word1 is empty, so the operation is n times
        for(int i= 1; i<= n; ++i)
            dp[0][i] = i;
        
        
        for(int i = 1; i<= m; ++i){
            for(int j= 1; j<= n; ++j){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    //replace: means till the dp[i-1][j-1] is the same, add 1 operation by replacement
                    //  example: word1: "ABCDE", word2: "ABCDF" 
                    //           therefore, only needs to 1 move based on dp[i-1][j-1]
                    
                    //deletion: the question is convert from word1 to word2, 
                    //          means till the dp[i-1][j] is the same, add 1 ...
                    //  example: word1: "ABCDE", word2: "ABCD". i=4 j=3
                    //           add 1 move based on dp[i-1][j]
                    
                    //insertion: the question is convert from word1 to word2, 
                    //          means till the dp[i][j-1] is the same, add 1 ...
                    //  example: word1: "ABCD", word2: "ABCDE". i=3 j=4
                    //           add 1 move based on dp[i][j-1]
                    dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        }
        
        return dp[m][n];
    }
};