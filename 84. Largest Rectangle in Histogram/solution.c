/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.

*/
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {            
        int ret = 0;
        height.push_back(0);
        vector<int> index;
        for(auto n: height)
            cout<<n<<endl;
            
            for(int i = 0; i < height.size(); i++)
            {
                cout<< "i: "<<i<<endl;
                if(i == 4) cout<<index.size()<<endl;
                while(index.size() > 0 && height[index.back()] >= height[i])
                {
                    int h = height[index.back()];
                    cout<< "h:" <<h;
                    index.pop_back();
                    
                    int sidx = index.size() > 0 ? index.back() : -1;
                    cout<< ", sidx:" <<sidx;
                    if(h * (i-sidx-1) > ret)
                        ret = h * (i-sidx-1);
                    cout<< ", calculate:" <<h * (i-sidx-1)<<endl;
                }
                cout<< "ret: "<<ret<<endl;
                index.push_back(i);
            }
            
            return ret;
    }
};