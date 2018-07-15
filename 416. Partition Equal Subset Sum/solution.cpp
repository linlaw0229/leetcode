class Solution {
private:
    bool canReach(vector<int>& nums, int n, int start, int target, int left) {
        // n: nums.size()
        // start: DFS from the index "start" to the end
        // target: 
        // left: the sum of nums waiting to traversal, 
        //       i.e. sum of { nums[start], nums[start+1], ..., nums[n-1] }
        
        for (int i = start; i < n; ++i) {
            left -= nums[i];
            
            // nums[i] > target: too greater to choose now!
            if (nums[i] > target)    continue;
            
            // left == target: choose all the nums left
            if (nums[i] == target || left == target)   return true;
            
            // choose nums[i] and go further
            if (canReach(nums, n, i+1, target - nums[i], left)) return true;
            
            // Do not choose nums[i], go further
            // left < target: no need to traversal
            if (left < target)  return false;
        }
        return false;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num: nums)  total += num;
        if(total & 1)   return false;
        // sort to be descending
        sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
        return canReach(nums, nums.size(), 0, total >> 1, total);
    }
};