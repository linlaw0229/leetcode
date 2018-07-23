/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/
//O(nlogn)
//space: O(1) or O(n)For the implementations provided here, 
//the space complexity is constant because we sort the input array in place. 
//If we are not allowed to modify the input array, we must spend linear space to store a sorted copy.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int maxseq= 1;
        int curseq= 1;
        for(int i= 1; i< nums.size(); i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1]+1)
                    curseq++;
                else{
                    maxseq= max(curseq, maxseq);
                    curseq= 1;
                }
            }
        }
        return max(maxseq, curseq);
    }
};