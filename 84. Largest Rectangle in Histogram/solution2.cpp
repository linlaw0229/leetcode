//O(n^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res= 0;
        for(int i= 0; i< heights.size(); i++){ //go toward left
            if(i== heights.size()-1 || heights[i]> heights[i+1]){ //reached end || height[i]> height[i+1]
                int minh= heights[i];
                for(int j= i; j>=0; j--){ //go toward right, find every rectangle
                    minh= min(minh, heights[j]);
                    int area= minh* (i-j+1);
                    res= max(res, area);
                }
            }
        }
        return res;
    }
};