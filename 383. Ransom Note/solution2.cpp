class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;
        for(auto m: magazine)
            mag[m]++;
        
        for(auto r: ransomNote)
            if(--mag[r] < 0) return false;
        
        return true;
    }
};