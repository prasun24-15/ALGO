  vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(auto &i:edges)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty())
        {
            int topi=q.front();
            q.pop();
            topo.push_back(topi);
            for(auto &i:adj[topi])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        return topo;
        
    }
