class Solution {
public:
    int findContentChildren(vector<int>& child, vector<int>& cookie) {
        sort(child.begin(), child.end());
        sort(cookie.begin(), cookie.end());
        int i = 0, j=0;
        while(i< child.size() && j< cookie.size()){
            if(cookie[j] >= child[i])
                i++; // when the child get the cookie, foward child by 1
            j++;
        }
        return i;
    }
};