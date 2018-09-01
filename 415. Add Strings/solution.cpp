/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1= num1.length()-1, l2= num2.length()-1;
        int carry= 0;
        string res;
        while(l1 >= 0 || l2 >= 0 || carry){
            int sum= 0;
            sum+= carry;
            if(l1>= 0) {
                sum+= (num1[l1]- '0');
                l1--;
            }
            if(l2 >= 0){
                sum+= (num2[l2]- '0');
                l2--;
            }
            
            carry= sum/10;
            sum= sum%10;
            res+= to_string(sum);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};