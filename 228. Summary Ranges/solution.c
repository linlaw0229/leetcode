/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 1){
            res.push_back(to_string(nums[0]));
            return res;
        }
        for(int i = 0; i< nums.size(); ++i){
            int cur= nums[i];
            while(i+1< nums.size() && (nums[i+1]- nums[i]== 1)){
                i++;
            }
            if(cur != nums[i])
                res.push_back(to_string(cur)+"->"+to_string(nums[i]));
            else
                res.push_back(to_string(nums[i]));
        }
        
        return res;
    }
};