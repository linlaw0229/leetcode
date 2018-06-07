/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int n: nums)
            ++map[n]; //put elements in map, increase the frequency
        
        vector<vector<int>> buckets(nums.size()+1); //size()+1 is because the sequence might full with the same element
        for(auto p: map)
            buckets[p.second].push_back(p.first); //use frequency as index, put elements with same frequency into the same box
        
        vector<int> ans;
        for(int i= buckets.size()-1; i>=0 && ans.size() < k; --i){ //start from right side, because we want to find top k frequent
            for(int num: buckets[i]){
                ans.push_back(num);
                if(ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};

