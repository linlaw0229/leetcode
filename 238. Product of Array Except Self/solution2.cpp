class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> res(length, 1);
        int left= 1, right= 1;;
        
        for(int i= 0, j= length-1; i< length; i++, j--){
            res[i]*= left;
            left*= nums[i];
            res[j]*= right;
            right*= nums[j];
        }
        return res;
    }
};

/*

        3   4   5   6
left=1 1*1  
        -> 1*3  
             ->3*4  
                 -> 3*4*5

        3   4   5   6
                   1*1  right=1
               1*6 <-
           5*6  <-
      4*5*6  <-
      
do same work, can use one for loop
      
*/