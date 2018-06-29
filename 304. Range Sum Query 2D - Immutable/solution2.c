class NumMatrix {
public:
    vector<vector<int>> _sum;
    
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        _sum.clear();
        _sum.resize(matrix.size()+1, vector<int> (matrix[0].size()+1, 0));
        for(int r= 1; r<= matrix.size(); r++){
            for(int c= 1; c<= matrix[0].size(); c++){
                _sum[r][c]= matrix[r-1][c-1]
                            +_sum[r-1][c]
                            +_sum[r][c-1]
                            -_sum[r-1][c-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        return _sum[row2+1][col2+1] 
            - _sum[row1][col2+1] 
            - _sum[row2+1][col1] 
            + _sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */