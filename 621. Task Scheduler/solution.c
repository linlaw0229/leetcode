/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26, 0); //only 26 character
        for (auto c: tasks) 
            map[c - 'A']++; //count which task has the largest frequency
        
        sort(map.begin(), map.end());
        
        int max_val = map[25] - 1; //last element do not need cool down
        int idle_slots = max_val * n;
        for (int i = 24; i >= 0 && map[i] > 0; i--) { 
            //already set up the largest one, so start at i=24
            idle_slots -= min(map[i], max_val);
        }
        return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
    }
};