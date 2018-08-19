class Solution {
public:
    int numDecodings(string s) {
        /*
        use 1d dp array to sum up how many ways from beginning
        dp[i-1]: 1 digit: can not be zero 
        dp[i-2]: 2 digits: can not exceed 26, digit of ten can not be zero
        */
        int n= s.length();
        if(!n) return 0;
        vector<int> dp(n+1, 0);
        dp[0]= 1; //empty string only one way to decode
        
        //since the dp equation needs dp[i-1] and dp[i-2] to calculate
        //we also need to init dp[1]
        dp[1]= s[0] == '0'? 0:1; 
        
        for(int i= 2; i< dp.size(); i++){
            int n1= stoi(s.substr(i-1, 1));
            //cout<<n1<<endl;
            int n2= stoi(s.substr(i-2, 2));
            //cout<<n2<<endl<<endl;
            
            if(n1>= 1 && n1 <= 9) dp[i]+= dp[i-1];
            if(n2>= 10 && n2 <= 26) dp[i]+= dp[i-2];
        }
        return dp[n];
    }
};