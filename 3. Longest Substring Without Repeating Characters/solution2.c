class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        unordered_map<char, int> map;
        int maxl = 0, left= -1;
        for(int i= 0; i< s.length(); i++){
            if(map.find(s[i]) != map.end()){ //check whether if the character already in the map
                left = max(map.find(s[i])->second, left); //if we can find, update the left pointer
            }
            map[s[i]] = i; //update the appearance position of the character in map
            maxl = max(maxl, i-left); //max length would remain the same or (cur position-left pointer)
        }
        return maxl;
    }
};