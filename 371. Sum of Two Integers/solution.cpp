/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

class Solution {
public:
    int getSum(int a, int b) {
        /*
        1. use XOR to get different bits. 
        2. if both 1, shift left
        3. if only 1, XOR can help to sum it into result
        
        101     
        110
        */
        
        int sum= 0;
        while(b != 0){
            sum = a^b; 
            b= (a&b)<<1;
            a= sum;
        }
        return a;
    }
};