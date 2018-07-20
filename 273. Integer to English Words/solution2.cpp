class Solution {
public:
    vector<string> less_than_20= {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens= {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands= {"", "Thousand", "Million", "Billion"};
    
    string numberToWords(int num) {
        if(num== 0) return "Zero";
        int i= 0;
        string res= "";
        
        while(num> 0){
            if(num% 1000 != 0)
                res= helper(num%1000)+ thousands[i]+ " "+ res;
            num/= 1000;
            i++;
        }
        return res.substr(0, res.find_last_not_of(' ')+1);;
    }
    
    string helper(int num){
        if(num== 0) return "";
        else if(num < 20)
            return less_than_20[num]+ " ";
        else if(num < 100)
            return tens[num/10]+ " "+ helper(num%10);
        else
            return less_than_20[num/100]+ " Hundred "+ helper(num%100);
    }
};