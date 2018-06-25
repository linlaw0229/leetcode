/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/

class Solution {
public:
    int binarysearch(vector<int>& nums, int l, int r, int x){
        while(r >= l && r < nums.size()){
            int mid= (l+r)/2;
            if(nums[mid] >= x)
                r= mid-1;
            else
                l= mid+1;
        }
        return l;
    }
    
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int count= 0;
        sort(nums.begin(), nums.end());
        for(int i= 0; i< nums.size()-2; i++){
            int k= i+2;
            for(int j= i+1; j< nums.size()-1 && nums[i]!= 0; j++){
                k= binarysearch(nums, k, nums.size()-1, nums[i]+nums[j]);
                count += k-j-1;
            }
        }
        return count;
    }
};
