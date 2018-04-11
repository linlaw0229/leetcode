/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
    // store the result that is the max we have found so far
        int r = nums[0];

        // imax/imin stores the max/min product of
        // subarray that ends with the current number A[i]
        for (int i = 1, imax = r, imin = r; i < nums.size(); i++) {
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them
            if (nums[i] < 0)
                swap(imax, imin);

            // max/min product for the current number is either the current number itself
            // or the max/min by the previous number times the current one
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            // the newly computed max value is a candidate for our global result
            r = max(r, imax);
        }
        return r;
    
    }
};
