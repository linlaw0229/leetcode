/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int r= t.length();
        int c= s.length();
        
        vector<vector<int>> dp(r+1, vector<int>(c+1, 0));
        
        for(int i= 0; i< c; i++)
            dp[0][i]= 1; //for every substring in s with length i, we can match an empty string when t is empty
        
        for(int i= 1; i<= r; i++){
            for(int j= 1; j<= c; j++){
                if(t[i-1] != s[j-1])
                    dp[i][j]= dp[i][j-1]; //find previous matching one(previous s matched with t)
                else
                    dp[i][j]= dp[i][j-1]+ dp[i-1][j-1]; //characters are the same, d=
            }
        }
        
        return dp[r][c];
    }
};
