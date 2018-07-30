/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Example 1:

Input: "112358"
Output: true 
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true 
Explanation: The additive sequence is: 1, 99, 100, 199. 
             1 + 99 = 100, 99 + 100 = 199
Follow up:
How would you handle overflow for very large input integers?
*/

class Solution {
public:
    bool isAdditiveNumber(string num) {
        /*
        1. think about how to devide the string. it should be three part.
        2. need a sub function for add string.
        3. a sub function to check if three strings can form additive sequence.
        */
        for(int i= 1; i<= num.length()/2; i++){ //start from 1 is because substr is [0, i)
            for(int j= 1; j<= (num.length()-i)/2; j++){
                if(check(num.substr(0, i), num.substr(i, j), num.substr(i+j))) //
                    return true;
            }
        }
        return false;
    }
    
    bool check(string num1, string num2, string num3){
        if(num1.length()> 1 && num1[0] == '0' || num2.length()> 1 && num2[0] == '0')
            return false;
        string sum = add(num1, num2);
        if(sum == num3) return true;
        
        //can not divide num3 to sum because length of sum is larger, return false
        //num3 does not contain equal string of sum in itself, return false
        if(sum.length() >= num3.length() || num3.substr(0, sum.length()) != sum)
            return false;
        else{
            //recursively find following string
            return check(num2, sum, num3.substr(sum.length()));
        }
    }
    
    
    string add(string num1, string num2){
        /*
        1. start from right to left, then reverse the string
        2. make sure the carry is added
        3. use (char - '0') to calculate digits
        */
        string res;
        int sum= 0, carry= 0;
        int n= num1.length()-1, m= num2.length()-1;
        while(n>= 0 ||m >= 0){
            sum= carry+ (n>= 0 ? num1[n--]-'0': 0)+ (m>= 0? num2[m--]-'0': 0);
            res.push_back(sum%10 + '0');
            carry= sum/10;
        }
        if(carry) res.push_back(carry+ '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
