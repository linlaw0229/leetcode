/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        /*
        1. chech numerator is 0 or not
        2. possible overflow, so type use long
        3. positive or negative
        */
        if(numerator == 0) return "0";
        
        string res= "";
        //this string is for return the result, first should check the sign
        res= (numerator>0) ^ (denominator>0)? "-":""; //if different sign, then it's negative
        
        //after getting sign, compute with absolute value
        long num= (numerator> 0)? (long)numerator: (long)numerator*-1;
        long den= (denominator> 0)? (long)denominator: (long)denominator*-1;
        
        res.append(to_string(num/den)); //the integer part
        num %= den; //the remain part
        
        if(num == 0) return res; 
        
        res.append(".");
        unordered_map<long, int> memo; //long
        num*= 10;
        while(num!= 0){
            if(memo.find(num) != memo.end()){
                res.insert(memo[num], "(");
                res.append(")");
                break;
            }
            memo[num]= res.size();
            res.append(to_string(num/den));
            num = (num%den)*10;
        }
        return res;
    }
};