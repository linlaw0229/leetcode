class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<= 0) return false;
        //if n is a power of two, for example: 1000
        //n-1 will be 0111
        //n&(n-1) will be False
        return !(n&(n-1));
    }
};