/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.

*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        //first of all, the description told us, 
        //(A,B) and (E,F) are the bottom left most corner of the rectangle
        //(C,D) and (G,H) are the top right most corner
        
        int areaA = (C-A) * (D-B);
        int areaB = (G-E) * (H-F);
        
        int left = max(A, E);
        int right = min(G, C);
        int bottom = max(F, B);
        int top = min(D, H);
        
        //If overlap
        int overlap = 0;
        if(right > left && top > bottom)
             overlap = (right - left) * (top - bottom);
        
        return areaA + areaB - overlap;
    }
};