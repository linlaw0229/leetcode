/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false

*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        //two pointers
        
        unordered_map<char, char> dict{{'0','0'},{'1','1'}, {'6','9'}, {'9','6'}, {'8','8'}};
        
        for(int left= 0, right= num.length()-1; left<= right; left++, right--){
            if(dict.find(num[left]) == dict.end() || dict[num[left]] != num[right])
                return false;
        }
        return true;
    }
};