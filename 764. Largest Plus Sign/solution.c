/*
In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, and right, and made of 1s. This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.

Examples of Axis-Aligned Plus Signs of Order k:

Order 1:
000
010
000

Order 2:
00000
00100
01110
00100
00000

Order 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000
Example 1:

Input: N = 5, mines = [[4, 2]]
Output: 2
Explanation:
11111
11111
11111
11111
11011
In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.
Example 2:

Input: N = 2, mines = []
Output: 1
Explanation:
There is no plus sign of order 2, but there is of order 1.
Example 3:

Input: N = 1, mines = [[0, 0]]
Output: 0
Explanation:
There is no plus sign, so return 0.
Note:

N will be an integer in the range [1, 500].
mines will have length at most 5000.
mines[i] will be length 2 and consist of integers in the range [0, N-1].
(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)
*/

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, N));
        //use a 2d array to calculate the maximum plus sign in each grid[i][j]
        for(auto m: mines) //m: vector<int>
            grid[m[0]][m[1]] = 0;
        //set the mines position to 0
        
        for(int i= 0; i< N; i++){
            for(int j= 0, l= 0; j< N; j++){
                //go from left to right, to count the max length of left
                // j is a column index, iterate from left to right
                // every time check how far left it can reach.
                // if grid[i][j] is 0, l needs to start over from 0 again, otherwise increment
                grid[i][j] = min(grid[i][j], l= (grid[i][j] == 0 ? 0: l+1));
            }
            
            for(int k= N-1, r= 0; k>=0; k--){
                // k is a column index, iterate from right to left
                // every time check how far right it can reach.
                // if grid[i][k] is 0, r needs to start over from 0 again, otherwise increment
                grid[i][k] = min(grid[i][k], r= (grid[i][k] == 0 ? 0: r+1));
            }
            
            for(int j= 0, u= 0; j< N; j++){
                // j is a row index, iterate from top to bottom
                // every time check how far up it can reach.
                // if grid[j][i] is 0, u needs to start over from 0 again, otherwise increment
                grid[j][i] = min(grid[j][i], u= (grid[j][i] == 0 ? 0: u+1));
            }
            
            for(int k= N-1, d= 0; k>=0; k--){
                // k is a row index, iterate from bottom to top
                // every time check how far down it can reach.
                // if grid[k][i] is 0, d needs to start over from 0 again, otherwise increment
                grid[k][i] = min(grid[k][i], d= (grid[k][i] == 0 ? 0: d+1));
            }
        }
        
        int res= 0;
        for(int i= 0; i< N; i++){
            for(int j= 0; j< N; j++){
                res= max(res, grid[i][j]);
            }
        }
        return res;
    }
};