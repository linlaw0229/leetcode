class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int reach=0; //where is the farest that it can reach
        int i=0; //current location
        while(i< nums.size() && i<=reach){
            reach=max(reach, i+nums[i]);
            i++;
        }
        return reach>=nums.size()-1; //check whether reach is greater than array size
    }
};