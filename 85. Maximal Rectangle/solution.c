/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size() <= 0 || matrix[0].size()<= 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size() + 1;
        //take care of the size, because we need to calculate the item in stack twice
        //just like 84., also need to push last item to the stack
        int h= 0, w= 0, ret= 0;
        vector<int> height(n, 0);
        
        for(int i= 0; i< m; ++i){
            stack<int> s;
            for(int j= 0; j< n; ++j){
                //set height, 
                if(j < n-1){
                    //this is to check whether the j is the extra boundary case we need to calculate
                    if(matrix[i][j] == '1') height[j]+= 1;
                    else height[j] = 0;
                }
                
                //this is pretty similiar to 84
                while(!s.empty() && height[s.top()] >= height[j]){
                    cout<< s.top()<<endl;
                    h = height[s.top()];
                    s.pop();
                    w = s.empty() ? j: j-s.top()-1;
                    cout<< "h= "<< h<<", w= "<<w<<endl;
                    if(h*w > ret) ret = h*w;
                }
                s.push(j);
                cout<< "j= "<<j<<endl;
            }
        }
        return ret;   
        

    }
};