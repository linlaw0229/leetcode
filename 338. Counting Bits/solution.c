/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Credits:
Special thanks to @ syedee for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1);
        for(int i=1; i<=num; ++i){
            result[i] = result[i & (i-1)] +1;
        }
        return result;
    }
};
/*

1     01    1
2     10    1
3    011    2
4    100    1
5    101    2
6    110    2
7    111    3
8   1000    1
9   1001    2
10  1010    2
11  1011    3
12  1100    2
13  1101    3
14  1110    3
15  1111    4
