//space O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
    int n = triangle.size();
	vector<vector<int>> f(n+1, vector<int>(n + 1, INT_MAX));

	for(int i=1; i<=n; ++i){
		for(int j=1; j<=i;++j){
	    	f[i][j] = triangle[i-1][j-1];
	    	if(i==1 &&j==1) continue; //edge case, only 1 item at top
            if(j==1) f[i][j]+= f[i-1][j]; //edge case, first item in each row
			else if(j==i) f[i][j] += f[i-1][j-1]; //edge case, last item in each row
			else
				f[i][j] += min(f[i-1][j], f[i-1][j - 1]);
		}
        //swap(f[0], f[1]);
    }
	return *min_element(f[n].cbegin(), f[n].cend());
}

};

// improved to use space O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
    int n = triangle.size();
	vector<vector<int>> f(2, vector<int>(n + 1, INT_MAX));

	for(int i=1; i<=n; ++i){
		for(int j=1; j<=i;++j){
	    	f[1][j] = triangle[i-1][j-1];
	    	if(i==1 &&j==1) continue; //edge case, only 1 item at top
            if(j==1) f[1][j]+= f[0][j]; //edge case, first item in each row
			else if(j==i) f[1][j] += f[0][j-1]; //edge case, last item in each row
			else
				f[1][j] += min(f[0][j], f[0][j - 1]);
		}
        swap(f[0], f[1]);
    }
	return *min_element(f[0].cbegin(), f[0].cend());
}

};