class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;      //  stack for keeping track of bars position
        int ts;             //  To store top of stack
        int max_area = 0;   //  initial maximum area         
        int new_area;       //  getting area with top bar
        int i = 0, total = heights.size();

        while (i < total){      //  working with all bars
            if (st.empty() || heights[st.top()] <= heights[i])  
                //  if the current bar's height is bigger or equal than the top of stack
                st.push(i++); 

            else {   //  if the current bar's height is less than the top of stack
                ts = st.top();  
                st.pop();  
                new_area = heights[ts] * (st.empty() ? i : i - st.top() - 1);   //  finding the new area
                // update max area, if needed
                if (max_area < new_area) max_area = new_area;                
            }      
        }

        //  finding area for the rest of the bars still in stack
        
        
        while (st.empty() == false) {
            ts = st.top();
            st.pop();
            new_area = heights[ts] * (st.empty() ? i : i - st.top() - 1);
            
            if (max_area < new_area) max_area = new_area;
        }
        return max_area;
    }

};