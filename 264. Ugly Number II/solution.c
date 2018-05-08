/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> result(1, 1);
        int i=0, j=0, k=0; // for pointing the position of current 2, 3, 5
        
        while(n> result.size()){
            result.push_back(min(result[i]*2, min(result[j]*3, result[k]*5))); //calculate which is the next minimum ugly number
            if(result.back() == result[i]*2) ++i;
            if(result.back() == result[j]*3) ++j;
            if(result.back() == result[k]*5) ++k;
        }
        
        return result.back();
    }
};
