class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> record(nums.begin(), nums.end());
        int res= 1;
        for(auto n: nums){
            if(!record.count(n)) continue;
            record.erase(n);
            
            //use two pointer search toward left and right to find the largest range
            int left= n-1, right= n+1;
            while(record.count(left)) record.erase(left--);
            while(record.count(right)) record.erase(right++);
            
            res= max(res, right-left-1);
        }
        return res;
    }
};