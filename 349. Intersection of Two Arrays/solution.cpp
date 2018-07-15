/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //chekc how many distinct element are the same
        unordered_set<int> check(nums1.begin(), nums1.end());
        vector<int> res;
        for(auto n: nums2){
            if(check.count(n)){
                res.push_back(n);
                check.erase(n);
            }
        }
        return res;
    }
};