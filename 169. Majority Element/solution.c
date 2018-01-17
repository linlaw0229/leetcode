/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int count = 0;
        for(auto &n: nums){
            if(count == 0){
                candidate = n;
            }
            count += (n == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
