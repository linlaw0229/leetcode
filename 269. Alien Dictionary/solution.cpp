/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0) return "";
        unordered_map<char, int> indegree;
        unordered_map<char, multiset<char>> hash;
        for(auto word: words)
            for(auto ch: word)
                indegree[ch]= 0;
        
        for(int i= 1; i< words.size(); i++){
            int k= 0, len1= words[i-1].length(), len2= words[i].length();
            //example: wrt, wrf
            while(words[i-1][k] == words[i][k]) //skip same characters
                k++; //ex: wrt, wrf. skip 'w', 'r'
            
            if(k>= min(len1, len2)) continue; //exceed one of the length
            indegree[words[i][k]]++; //ex: 'f' comes after 't', so indegree[f]++.
            hash[words[i-1][k]].insert(words[i][k]); //since wrf is after wrt. hash[t]= [f, ...]
        }
        
        string ans;
        for(int i= 0; i< indegree.size(); i++){
            char ch= ' ';
            for(auto val: indegree){ //ex: indegree[t]= 0, indegree[f]= 1
                if(!val.second){ //find node that indegree == 0
                    ch= val.first;
                    break;
                }
            }
            if(ch == ' ') return ""; //no one is indegree 0, that means have a cycle and is invalid
            ans+= ch; //append character with indegree= 0 to result
            //cout<<"ch: "<<ch<<" ,"<<indegree[ch];
            indegree[ch]--; 
            //cout<<", "<<indegree[ch]<<endl;
            for(auto val: hash[ch]) 
                indegree[val]--; //every string comes after 
        }
        return ans;
    }
};
