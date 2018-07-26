/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/

class Solution {
public:
    string reverseVowels(string s) {
        if(s.empty()) return s;
        unordered_set<char> set{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left= 0, right= s.length()-1;
        while(left< right && left< s.length() && right> 0){
            while(set.find(s[left]) == set.end() && left< right) left++;
            while(set.find(s[right])== set.end() && left< right) right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};