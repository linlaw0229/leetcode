/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
class Solution {
public:
    int countPrimes(int n) {
        /*
        1. use an array to denote every number in n
        2. for every i, mark out it's multiple in range n
        */
        vector<int> primes(n+1, 1);
        primes[0]= 0;
        primes[1]= 0;
        int res= 0;
        for(int i= 2; i< n; i++){
            if(primes[i]== 1){
                for(int j= 2; i*j<=n; j++)
                    //mark out every multiple of i in array primes
                    primes[i*j]= 0; 
                res++;
            }
        }
        return res;
    }
};