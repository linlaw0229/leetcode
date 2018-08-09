/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        /*
        1. create a graph for dfs
        2. if we can find a cycle, then we can not finish all courses. 
        */
        vector<unordered_set<int>> graph(numCourses);
        for(auto n: prerequisites){
            graph[n.second].insert(n.first); 
            // [1, 0]: To take course 1 you should have finished course 0
            // So we need an edge from 0->1, because we need to get to 0 then 1
        }
        vector<bool> visited(numCourses, false), onpath(numCourses, false); //the second one is to check cycle
        for(int i= 0; i< numCourses; i++){
            if(!visited[i] && dfscycle(graph, visited, onpath, i))
                return false;
        }
        return true;
    }
    
    bool dfscycle(vector<unordered_set<int>>& graph, vector<bool>& visited, vector<bool>& onpath, int index){
        if(visited[index]) return false; //already traversed this node in big picture
        
        onpath[index]= visited[index]= true; //set to true denoted that we traverse this node
        for(auto neighbor: graph[index]){ //check all next level as node index is the prerequist
            if(onpath[neighbor] || dfscycle(graph, visited, onpath, neighbor)) 
                return true;
            //1. onpath[neighbor] is true, means that this neighbor is already in this subpath, so we have a cycle
            //2. dfscycle, go further and find a cycle in subpath
        }
        onpath[index]= false; //reset to false
        return false;
    }
};