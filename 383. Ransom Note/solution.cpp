/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;
        for(char m: magazine){
            mag[m]++;
        }
        
        int i= 0;
        while(i< ransomNote.length()){
            if(mag.find(ransomNote[i]) == mag.end() || mag[ransomNote[i]]== 0)
                return false;
            else
                mag[ransomNote[i++]]--;
        }
        return true;
    }
};