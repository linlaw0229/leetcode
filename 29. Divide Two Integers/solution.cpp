/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        /*
        use deduction to get the quotient. 
        but deduct one by one is too slow, so we can use shifting to speed up the process
        ex:
        d1: 15, d2: 3
        shift d2 left to get multipy
        */
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int res= 0;
        int sign = (dividend> 0 ^ divisor>0)? -1: 1;
        long long d1= labs(dividend), d2= labs(divisor);
        while(d1>= d2){
            long long tmp= d2;
            int multiply= 1;
            while(d1>= tmp<<1){
                tmp <<= 1;
                multiply<<=1;
            }
            d1-= tmp;
            res+= multiply;
        }
        
        return res*sign;
    }
};