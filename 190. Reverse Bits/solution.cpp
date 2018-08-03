/*
Reverse bits of a given 32 bits unsigned integer.

Example:

Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
             return 964176192 represented in binary as 00111001011110000010100101000000.
Follow up:
If this function is called many times, how would you optimize it?


*/
/*
example: 01101100
shift       res
0               0
1              00
2             001
3            1100
4           00110
5          001101
6         0011011
7        00110110

...    add zero
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res= 0;
        for(int i= 0; i< 32; i++){
            res = (res<<1) + (n>>i &1);
        }
        return res;
    }
};