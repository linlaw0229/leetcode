/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
    vector<string> result;
    if(digits.empty()) return vector<string>();
        
    vector<string> dictionary = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");
        
    for(int i = 0; i< digits.size(); i++){
        int num = digits[i]- '0';
        if(num <0 || num >9) break;
        
        string candidate = dictionary[num];
        if(candidate.empty()) continue;
        
        vector<string> tmp;
        for(int j = 0; j< candidate.size(); ++j){
            for(int k = 0; k< result.size(); ++k){
                tmp.push_back(result[k] + candidate[j]);
            }
        }
        result.swap(tmp);
        
    }
    return result;

}
};
