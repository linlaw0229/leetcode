class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(A.size(), 0);
        if(A.size() < 3) return 0;
        if(A[1]-A[0] == A[2]-A[1])
            dp[2]= 1;
        int res= dp[2];

        for(int i= 3; i< A.size(); i++){
            if(A[i]- A[i-1] == A[i-1]-A[i-2]){
                dp[i] = dp[i-1]+1;
                res += dp[i];
            }
        }
        return res;
        //dp[i]: number of arithmetic slices ends at A[i]
        //if(A[i]- A[i-1] == A[i-1] - A[i-2]), it's a new slice
        //we can look previous, A[i-3], A[i-2], A[i-1].
        //number of slices ends at A[i-1] will store at dp[i-1]
        //so total slices ends at A[i] is dp[i-1]+1
    }
};