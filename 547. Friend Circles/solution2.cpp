class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        //BFS
        int n= M.size(), res= 0;
        queue<int> q;
        vector<int> visited(n, 0);
        for(int i= 0; i< n; i++){
            if(visited[i]) continue;
            q.push(i);
            while(!q.empty()){
                int tmp= q.front();
                q.pop();
                visited[tmp]= true;
                for(int j= 0; j< n; j++){
                    if(visited[j] || !M[tmp][j]) continue;
                    q.push(j);
                }
            }
            res++;
        }
        return res;
    }
};