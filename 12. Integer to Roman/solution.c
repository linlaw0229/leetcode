/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
        string dict[13]= {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[13]= {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string _return;
        for(int i=0; i< 13; i++){
            while(num >= val[i]){
                num -= val[i];
                _return+= dict[i];
            }
        }
        return _return;
    }
};
        
