class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        stack<int> stk;
        int n= height.size();
        int maxArea= 0;
        int h, w;
        
        for(int i= 0; i< n; i++){
            if(stk.empty() || height[stk.top()] < height[i]) 
                stk.push(i);
            else{
                while(!stk.empty() && height[i]<= height[stk.top()]){
                    h= height[stk.top()];
                    stk.pop();
                    w= stk.empty()? i: i-(stk.top()+1);
                    maxArea= max(maxArea, h*w);
                }
                stk.push(i);
            }
        }
        return maxArea;
    }
};
//https://goo.gl/p7zvxS