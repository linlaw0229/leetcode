/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
*/

class Solution {
public:
    bool isNumber(string s) {
        //"1 1"is not valid, "0x11" is not valid, "." is not valid, "2e3.1" is not valid, "2e" is not valid,"1a" is not valid,"++1" is not valid
        
        
        int i = 0;
        // skip the whilespaces
        while(s[i] == ' ') i++;

        // check the significand
        // skip the sign if exist
        if(s[i] == '+' || s[i] == '-') i++; 

        int n_nm= 0, n_pt= 0;
        while(isdigit(s[i]) || s[i] == '.')
            s[i++] == '.' ? n_pt++:n_nm++;       
        if(n_pt>1 || n_nm<1) // no more than one point, at least one digit
            return false;

        // check the exponent if exist
        if(s[i] == 'e') {
            i++;
            // skip the sign, " 005047e+6", it should also be true
            if(s[i] == '+' || s[i] == '-') i++; 

            int n_nm = 0;
            while(isdigit(s[i])){
                i++;
                n_nm++;
            }
            if(n_nm<1)
                return false;
        }

        // skip the trailing whitespaces
        while(s[i] == ' ')
            i++;
        
        // must reach the ending 0 of the string
        return s[i]== '\0'; 
    }
};