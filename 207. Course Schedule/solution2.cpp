class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //BFS
        /*
        1. calculate indegree for every node
        2. BFS, push every node with indegree 0 into queue
        3. check if every node has indegree 0
        */
        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto n: prerequisites){
            indegree[n.first]++;
            graph[n.second].push_back(n.first);
        }
        
        queue<int> q;
        for(int i= 0; i< numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            auto tmp= q.front(); q.pop();
            
            for(int i= 0; !graph[tmp].empty() && i< graph[tmp].size(); i++){
                if(--indegree[graph[tmp][i]] == 0) q.push(graph[tmp][i]);
            }
        }
        
        for(int i= 0; i< numCourses; i++){
            if(indegree[i] != 0) return false;
        }
        
        return true;
        
    }
};