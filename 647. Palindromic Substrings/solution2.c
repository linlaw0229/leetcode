class Solution {
public:
    int count= 0;
    int countSubstrings(string s) {
        int res= 0;
        for(int i= 0; i< s.length(); i++){
            expand(s, i, i);
            expand(s, i, i+1);
        }
        return count;
    }
    
    void expand(string s, int left, int right){
        while(left>= 0 && right < s.length() && s[left]==s[right]){
            left--;
            right++;
            count++;
        }
    }
};