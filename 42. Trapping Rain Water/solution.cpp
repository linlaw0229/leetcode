/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        //find boundary from left and right
        //kind of like build a wall whenever you see a mountain, the valley would be counted later
        vector<int> left(height.size(), 0), right(height.size(), 0);
        
        left[0]= height[0];
        for(int i= 1; i< height.size(); i++)
        //so we know this is how many water can be stored if we look from left
            left[i]= max(height[i], left[i-1]);
        
        int size= height.size();
        right[size-1]= height[size-1];
        for(int i= size-2; i>= 0; i--)
        //so we know this is how many water can be stored if we look from right
            right[i]= max(height[i], right[i+1]);
        
        int res= 0;
        for(int i= 0; i< size; i++){
            //the actual water can be stored is the min(left, right) - height
            //because the actual mountain height is min(left, right)
            res+= min(left[i], right[i])-height[i];
        }
        return res;
    }
};
//time: O(n)
//space: O(n)