/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long next= lower; //need to declare long to avoid overflow
        
        for(int i= 0; i< nums.size(); i++){
            if(nums[i] < next) continue;
            if(nums[i] == next){
                next++;
                continue;
            }
            res.push_back(getRange(next, nums[i]-1));
            next= (long)nums[i]+1;//need to declare long to avoid overflow
        }
        if(next <= upper) res.push_back(getRange(next, upper));
        
        return res;
    }
    
    string getRange(int lower, int upper){
        return (lower== upper) ? to_string(lower) : to_string(lower)+"->"+to_string(upper);
    }
};
