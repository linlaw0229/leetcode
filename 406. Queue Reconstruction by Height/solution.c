/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        //example:
        //before sorting: [7,1], [7,0], [5,2], [4,3]
        
        
        sort(people.begin(), people.end(),[](pair<int,int> p1, pair<int,int> p2){ //lamda function
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
            //true: [6,0], [4,0] or [6,2], [6,4]
        });
        //after sorting: [7,0], [7,1], [5,2], [4,3]
        
        vector<pair<int,int>> sol;
        for (auto person : people){ 
            sol.insert(sol.begin() + person.second, person); 
            
        }
        return sol;
    }
};