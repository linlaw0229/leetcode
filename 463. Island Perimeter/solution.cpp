/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int neighbor= 0, count= 0;
        for(int r= 0; r< grid.size(); r++){
            for(int c= 0; c< grid[0].size(); c++){
                if(grid[r][c] == 1){
                    //this is 1, search how many neighbor around it.
                    count++;
                    if(r != 0 && grid[r-1][c]== 1) neighbor++;
                    if(c != 0 && grid[r][c-1]== 1) neighbor++;
                }
            }
        }
        
        return count*4-neighbor*2;
    }
};
/*
+--+     +--+                   +--+--+
|  |  +  |  |          ->       |     |
+--+     +--+                   +--+--+
4 + 4 - ? = 6  -> ? = 2
*/