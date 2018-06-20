class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() < 1) return;
        bool even = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (even) { 
                if (nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i+1]);
                }
            } else {
                if (nums[i] < nums[i+1]) {
                    swap(nums[i], nums[i+1]);
                }
            }
            even = !even;
        }
    }
};