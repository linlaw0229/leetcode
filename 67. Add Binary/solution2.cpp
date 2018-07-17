class Solution {
public:
    string addBinary(string a, string b) {
        string res= "";
        int carry= 0;
        
        for(int i= a.length()-1, j= b.length()-1; i>= 0 || j>= 0; i--, j--){
            int m= (i>=0) && (a[i]=='1');
            int n= (j>=0) && (b[j]=='1');
            res= to_string((m+n+carry) & 1)+res;
            carry= (m+n+carry) >>1;
        }
        return carry== 1? '1'+res: res;
    }
};