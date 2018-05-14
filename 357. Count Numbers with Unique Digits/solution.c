/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, 
excluding [11,22,33,44,55,66,77,88,99])
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        /*
        if(n == 0) return 1;
        int res = 10; //original case
        int uniqueDigits = 9;
        int available = 9;
        
        while(n-- >1 && available >0){
            uniqueDigits = uniqueDigits* available; //recursively multiply the remain digits
            res += uniqueDigits; //The answer ask from 0<=x<= 10^n, so need to add the result
            available--;
        }
        return res;
        */
        if (n == 0) {
            return 1;
        }
        
        int ans = 10, base = 9;
        for (int i = 2; i <= n && i <= 10; i++) {
            base *= (9 - i + 2);
            ans += base;
        }
        return ans;
    }
        
};