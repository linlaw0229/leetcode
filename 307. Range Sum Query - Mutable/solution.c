/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

class NumArray {
public:
    NumArray(vector<int> nums) {
        num.resize(nums.size() +1);
        bit.resize(nums.size() +1);
        for(int i= 0; i< nums.size(); i++){
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff= val-num[i+1];
        
        for(int j= i+1; j< num.size(); j += j& -j){ //only modify logn elements for each iteration
            bit[j] += diff;
        }
        num[i+1] = val;
        /*
        example:
        i= 4
         4: 0000 0100
        -4: 1111 1100
        only change bit[4] and bit[8]
        */
    }
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }    
    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) {
            res += bit[j];
        }
        return res;
    }

private:
    vector<int> num;
    vector<int> bit;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */