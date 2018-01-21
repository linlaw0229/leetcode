/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.*/

class Solution {
public:
    int romanToInt(string s) {
        int _return = 0;
        _return = ToInt(s[0]);
        for(int i= 1; i< s.size(); i++){
            _return += ToInt(s[i]);
            (ToInt(s[i]) > ToInt(s[i-1])) ? _return-=(ToInt(s[i-1])*2): _return;
            
        }
        return _return;
    }
    
    int ToInt(char c){
        switch(c){
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            case 'I': return 1;
        }
        return 0;
    }
};
