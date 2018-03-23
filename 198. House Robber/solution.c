/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

//DP
class Solution {
public:
    int rob(vector<int>& nums) {
       
        int n=nums.size();
        
        //Edge Cases
        if(n==0) return 0;
        if(n<=2) return *max_element(nums.begin(),nums.end());
        
        
        int dp[n];
        dp[0]=nums[0]; //Represent starting from the odd house
        dp[1]=max(dp[0],nums[1]);//Represent max loot at the even house
        
        for(int i=2;i<nums.size();i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        
        return dp[n-1];
    }
};

//odd, even
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        
        //Edge Cases
        if(nums.size()==0) return 0;
        if(nums.size()<=2) return *max_element(nums.begin(),nums.end());
        
        int odd,even;
        odd=nums[0]; //Represent starting from the odd house
        even=nums[1];//Represent starting from the even house
        
        for(int i=2;i<nums.size();i++){

            if((i+1)%2==0) //Even
            {
                if(odd<even) odd=even; //If robbing even path gives more value then put odd as even
                even+=nums[i];
            }
            else //Odd
            {
                if(even<odd) even=odd;
                odd+=nums[i];
            }

        }
        
        return max(even,odd);
    }
};

*/
