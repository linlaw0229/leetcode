/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/

class Solution {
public:
    int mySqrt(int x) {
        /*
        x= (x/2)^2
        so use binary search to find a mid that close to sqrt(x)
        In while, If mid < sqrt(x), left = mid + 1 executed, right pointer is not moving, and right is the answer.

        If while, If mid > sqrt(x), right = mid - 1 executed, right pointer shifts left 1, closest to sqrt(x), right is also the answer.
        */
        
        int left= 1, right= x;
        while(left<= right){
            int mid= left+ (right-left)/2;
            if(mid == x/mid) return mid;
            else if(mid > x/mid) right= mid-1;
            else left= mid+1;
        }
        return right;
    }
};