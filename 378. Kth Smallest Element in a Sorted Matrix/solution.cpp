/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int left= matrix[0][0], right= matrix[n-1][n-1];
        while(left< right){
            int mid= left+ (right-left)/2;
            int count= 0, j= n-1;
            for(int i= 0; i< n; i++){
                while(j>= 0 && matrix[i][j]> mid) j--; //find the first element that is smaller than mid
                count += (j+1); //j was size-1, so need to plus 1
            }
            if(count< k) left= mid+1;
            else right= mid;
        }
        return left;
    }
};
