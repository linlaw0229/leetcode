/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string tmp= A;
        for(int i =1; i<= B.size()/ A.size() +2; ++i){
            if(tmp.find(B) != string::npos) 
                return i;
            tmp+=A;
        }
        return -1;
    }
};
