/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        //change the '.' to ' ', because istringstream can separate ' '
        for(auto& w : version1) if (w == '.') w=' ';
        for(auto& w : version2) if (w == '.') w=' ';
        
        istringstream s1(version1), s2(version2);
        while(1) {
            int n1,n2;
            if (!(s1 >> n1) ) n1 = 0; //no data left, so set to 0
            if (!(s2 >> n2) ) n2 = 0;
            if (!s1 && !s2) return 0; //both reached end
            if (n1<n2) return -1;
            if (n1>n2) return 1;
        }
    }
    
};