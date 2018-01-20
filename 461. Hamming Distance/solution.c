/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31.
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int a = x^y, _return = 0;
        
        while(a != 0){
            if(a & 1 != 0)
                _return++;
            a >>= 1;
        }
        return _return;
    }
};
