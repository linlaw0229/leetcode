class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
    int n = triangle.size();
	//vector<vector<int>> f(2, vector<int>(n + 1, INT_MAX));
    auto& t= triangle;

	for(int i=0; i<n; ++i){
		for(int j=0; j<=i;++j){
	    	if(i==0 && j==0) continue; //edge case, only 1 item at top
            if(j==0) t[i][j]+= t[i-1][j]; //edge case, first item in each row
			else if(j==i) t[i][j] += t[i-1][j-1]; //edge case, last item in each row
			else
				t[i][j] += min(t[i-1][j], t[i-1][j - 1]);
		}
    }
	return *min_element(t[n-1].cbegin(), t[n-1].cend());
}

};