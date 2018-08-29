class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
        //A[i][k]* B[k][j]= C[i][j]
        //C[i][j]= A[i][0]*B[0][j]+ A[i][1]*B[1][j]+ ... +A[i][k]*B[k][j]
        
        for(int i= 0; i< A.size(); i++){
            for(int k= 0; k< A[0].size(); k++){
                if(A[i][k] != 0){ //it's sparse matrix, this can reduce redundant calculation
                    for(int j= 0; j< B[0].size(); j++){
                        if(B[k][j] != 0) res[i][j]+= A[i][k]* B[k][j];
                    }
                }
            }
        }
        return res;
    }
};
