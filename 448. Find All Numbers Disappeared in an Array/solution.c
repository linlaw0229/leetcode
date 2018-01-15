/*Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i< nums.size(); i++){
            auto m = abs(nums[i]) -1;
            nums[m]= (nums[m] >0) ? -nums[m]: nums[m];
        }    
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] > 0)
                result.push_back(i+1);
        }
        
        return result;
    }
};
