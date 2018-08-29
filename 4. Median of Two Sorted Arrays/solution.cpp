/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+ nums2.size();
        if(total %2 == 1) //the array have odd number of elements, can find a middle one
            return findKth(nums1, 0, nums2, 0, total/2 +1);
        else
            //can not find a middle one, so need to find two numbers and divide by 2
            return (findKth(nums1, 0, nums2, 0, total/2)+ findKth(nums1, 0, nums2, 0, total/2 +1))/2;
    }
    
    double findKth(vector<int> &nums1, int i, vector<int>& nums2, int j, int k){
        if(nums1.size()- i > nums2.size()- j) return findKth(nums2, j, nums1, i, k);
        if(nums1.size() == i) return nums2[j+k-1];
        if(k == 1) return min(nums1[i], nums2[j]);
        
        int pa= min(i+k/2, int(nums1.size()) );
        int pb= j+k-pa+i;
        
        if(nums1[pa-1] < nums2[pb-1])
            return findKth(nums1, pa, nums2, j, k-pa+i);
        else if(nums1[pa-1]> nums2[pb-1])
            return findKth(nums1, i, nums2, pb, k-pb+j);
        else
            return nums1[pa-1];
    }
};
