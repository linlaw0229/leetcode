//O(n) space

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> visit(nums.size(), 0);
        int res= 0;
        
        for(int i= 0; i< nums.size(); i++){
            if(!visit[i]){ //not yet visited
                int start= nums[i], count= 0;
                do{
                    start= nums[start];
                    count++;
                    visit[start]= true;
                }while(start != nums[i]);
                res= max(res, count);
            }
        }
        return res;
    }
};

