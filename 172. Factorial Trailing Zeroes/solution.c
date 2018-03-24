/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/
class Solution {
public:
    int trailingZeroes(int n) {
    int result = 0;
        for(long long i=5; n/i>0; i*=5){
            result += (n/i);
        }
    return result;
    }
};

/*
How many multiples of 5 are there in the numbers from 1 to 100?

because 100 ÷ 5 = 20, so, there are twenty multiples of 5 between 1 and 100.

but wait, actually 25 is 5×5, so each multiple of 25 has an extra factor of 5, e.g. 25 × 4 = 100，which introduces extra of zero.

So, we need know how many multiples of 25 are between 1 and 100? Since 100 ÷ 25 = 4, there are four multiples of 25 between 1 and 100.

Finally, we get 20 + 4 = 24 trailing zeroes in 100!

The above example tell us, we need care about 5, 5×5, 5×5×5, 5×5×5×5 …
*/
