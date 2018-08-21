class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //quick sort: find a pivot and partition the list into two half. greater than pivot and smaller than pivot
        //if pivot is k-1th, then return
        int left= 0, right= nums.size()-1;
        while(1){
            int p= sort(nums, left, right);
            if(p == k-1)
                return nums[p];
            if(p < k-1)
                left= p+1;
            else
                right= p-1;
        }
    }
    
    int sort(vector<int>& nums, int left, int right){
        //use left most element as pivot, greater than pivot put left side.
        int pivot= nums[left]; 
        int l= left+1, r= right;
        while(l<= r){
            if(nums[l]< pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if(nums[l]>= pivot)
                l++;
            if(nums[r]<= pivot)
                r--;
        }
        //the nums[r] is greater than nums[left], so need to swap 
        swap(nums[left], nums[r]);
        return r;
    }
};
