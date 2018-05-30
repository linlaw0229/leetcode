/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int> > res( n, vector<int>(n) );
        int k = 1, i = 0;
        	while( k <= n * n )
        	{
        		int j = i;
                    // four steps
        		while( j < n - i )             // 1. horizonal, left to right
        			res[i][j++] = k++;
        		j = i + 1;
        		while( j < n - i )             // 2. vertical, top to bottom
        			res[j++][n-i-1] = k++;
        		j = n - i - 2;
        		while( j > i )                  // 3. horizonal, right to left 
        			res[n-i-1][j--] = k++;
        		j = n - i - 1;
        		while( j > i )                  // 4. vertical, bottom to  top 
        			res[j--][i] = k++;
        		i++;      // next loop
        	}
        	return res;
        
    }
};