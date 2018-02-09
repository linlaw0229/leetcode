/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".


*/

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string sum;
        int carry = 0;
        int n = max(a.size(),b.size());
        
        
        for(int i=0; i<n; i++){
            if(i< a.size())
                carry+= (a[i]-'0');
            if(i< b.size())
                carry+= (b[i]-'0');
            
            //printf("%c, %c, %d\n", a[i], b[i], carry);
            sum.push_back(carry%2+'0');
            //printf("%s\n", sum.c_str());
            carry/= 2;
        }
        
        if(carry) sum.push_back('1');
        //printf("%s\n", sum.c_str());
        reverse(sum.begin(),sum.end());
        return sum;
    }
};
