/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue; //skip duplicate element
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break; //because the array is sorted, if 4 elements start from i is greater than target, no need to do the rest
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue; //because the array is sorted, if 4 elements start from i is smaller than target, we should keep finding upcoming sequence
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue; 
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break; 
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1; //two pointer to search toward right and left
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{
                            left++;
                        }while(nums[left]==nums[left-1]&&left<right); //move left at least once then check for duplicate
                        
                        do{
                            right--;
                        }while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};