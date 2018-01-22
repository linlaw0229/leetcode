/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows< 2) return s;
        string _return;
        int inc = (nRows-1)*2;  // nRows>1, otherwise infinite while loop
        for(int i = 0; i < nRows; i++) {
            int j = i, d1 = (nRows-i-1)*2;
            while(j<s.size()) {
                //cout<<"s[j]"<<s[j]<<endl;
                _return.push_back(s[j]);
                if(d1!=0 && d1!=inc && j+d1<s.size()) {
                    _return.push_back(s[j+d1]);
                    //cout<<"s[j+d1]"<<s[j+d1]<<endl;
                }
                j += inc;
            }
        }
        return _return;
    }
};
