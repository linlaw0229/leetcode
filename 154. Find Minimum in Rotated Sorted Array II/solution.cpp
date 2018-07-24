/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left= 0, right= nums.size()-1;
        int mid= 0;
        while(left< right){
            mid= left+ (right-left)/2;
            if(nums[mid]> nums[right])
                left= mid+1; //set to mid+1 is because nums[mid] is definitely not the smallest element
            else if(nums[mid]< nums[right])
                right= mid;
            else
                //nums[mid]== nums[right]
                right--;
        }
        return nums[left];
    }
};