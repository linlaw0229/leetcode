/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/

class Solution {
public:
    string reorganizeString(string S) {
        /*
        1. count the frequency of each char
        2. put into priority queue
        3. the top 2 elements in queue must be the most frequently element, put them into result string first
        */
        unordered_map<char, int> map;
        for(auto c: S)
            map[c]++;
        
        priority_queue<pair<int, char>> q;
        for(auto n: map){
            if(n.second> (S.length()+1)/2) return ""; //Pigeonhole principal 
            q.push({n.second, n.first});
        }
        
        string res;
        while(q.size()>= 2){
            auto tmp1= q.top(); q.pop();
            auto tmp2= q.top(); q.pop();
            res.push_back(tmp1.second);
            res.push_back(tmp2.second);
            if(--tmp1.first > 0) q.push(tmp1);
            if(--tmp2.first > 0) q.push(tmp2);
        }
        if(!q.empty())
            res.push_back(q.top().second);
        return res;
    }
};