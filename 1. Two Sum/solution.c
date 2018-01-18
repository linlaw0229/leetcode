class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> _return;
        unordered_map<int, int> map;
        for(int i= 0; i<nums.size(); i++){
            map.insert(make_pair(nums[i], i));
        }
        
        for(int i= 0; i<nums.size(); i++){
            auto component= target- nums[i];
            auto p = map.find(component);
            if(p != map.end() && (p->second != i)){
                _return.push_back(i);
                _return.push_back(p->second);
            }
            if(_return.size()!= 0)
               break;
        }
        
        return _return;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> _return;
        for(auto i= 0; i<nums.size(); i++){
        for(auto j= 0; j<nums.size(); j++){
            if(i == j) continue;
            if(nums[i] + nums[j] == target){
                _return.push_back(i);
                _return.push_back(j);
            }
        }
        if(_return.size() != 0)
            break;
        }
    return _return;
    }
};
