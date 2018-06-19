class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int, vector<int>> map;
        for(int i= 0; i< nums.size(); i++){
            if(!map.count(nums[i])){
                vector<int> tmp= {1, i, i};
                map.insert(make_pair(nums[i], tmp)); //degree, first index of the key, last index of the key
            }
                
            else{
                auto tmp= map.find(nums[i]);
                tmp->second[0]++; //update degree
                tmp->second[2]= i;//update last appear index
            }
        }
        
        int degree= INT_MIN, res= INT_MAX;
        
        for(auto n: map){
            if(n.second[0] > degree){
                degree= n.second[0];
                res= n.second[2]- n.second[1] + 1;
            }
            else if (n.second[0] == degree){
                res = min(n.second[2] - n.second[1] + 1, res);
            }   
        }
        return res;
    }
};
