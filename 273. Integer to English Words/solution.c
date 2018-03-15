/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

class Solution {
public:
    vector<string> dict1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                          "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                          "Nineteen"};
    
    vector<string> dict2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    vector<string> v = {"Thousand", "Million", "Billion"};
    
    string numberToWords(int num) {
        if(!num) return "Zero";
        
        //cout<< INT_MAX<<endl;
        string res = "";
        
        res = int_string(num%1000);
        
        for(int i = 0; i< 3; ++i){
            num /= 1000;
            res = num % 1000 ? int_string(num % 1000) + " " + v[i] + " " + res : res;
        }
        
        while(res.back() == ' ') res.pop_back();
        
        return res;
    }
    
    string int_string(int num){
        int a = num/100, b= num%100, c= num%10;
        //printf("a =%d, b=%d, c=%d\n", a, b, c);
        string res;
        res += (b<20)? dict1[b]: dict2[b/10] + (c? " "+ dict1[c]: "");
        
        if(a)
             res = dict1[a] + " "+ "Hundred" + (b? " "+res: "");
        
        return res;
    }
    
};
