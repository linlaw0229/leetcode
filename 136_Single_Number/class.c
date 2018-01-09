class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        /*for(auto &i: nums){  //c++11, but the speed is slower than c++98
            result ^= i;
        }*/
            
        for (int i = 0; i<n; i++)
        {
            result ^=nums[i];
        }
        return result;
    }
};
