/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hset;
        
        for(int i = 0; i< nums.size(); ++i){
            if(hset.find(nums[i]) == hset.end())
                hset.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};


