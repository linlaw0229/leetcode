/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

//design a TrieNode class
class TrieNode{
public:
    TrieNode* child[26];
    bool isWord;
    TrieNode(): isWord(false){
        for(auto &c: child)
            c= NULL;
    }
};

class WordDictionary {
public:
    TrieNode* root; //global variable root
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* tmp= root;
        for(auto c: word){
            int i= c- 'a';
            if(!tmp->child[i]) 
                tmp->child[i]= new TrieNode();
            
            tmp = tmp->child[i];
        }
        tmp->isWord= true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        //need to consider the '.'
        //follow up: '*'
        return searchWord(word, root, 0);
    }
    
    bool searchWord(string &word, TrieNode *p, int i) {
        if(i == word.length()) return p->isWord;
        if(word[i] == '.'){
            for(auto c: p->child){
                //DFS, if child c is existed and we can find next character in trie, return true
                if(c && searchWord(word, c, i+1)) return true; 
            }
            return false; 
        }
        /* follow up for '*'
        else if (word[i] == '*') {
            if (i + 1 == word.size()) return true;
            if (searchWord(word, p, i + 1)) return true; // Skip *
            for (auto &a : p->child) {
                if (a && (a->child[word[i + 1] - 'a'] || word[i + 1] == '.' || word[i + 1] == '*') && searchWord(word, a, i + 1)) return true;
                if (a && searchWord(word, a, i)) return true;
            }
            return false;
        */
        
        else{
            int index= word[i]- 'a';
            return p->child[index] && searchWord(word, p->child[index], i+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */