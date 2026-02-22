class Solution {
  public:
    int timer=0;
    void dfs(int node,int parent,vector<vector<int>> &adj,int tin[],int low[],vector<int> &mark,vector<int> &vis)
    {
        vis[node]=1;
        tin[node]=low[node]=timer++;
        int child=0;
        for(auto &i : adj[node])
        {
            if(i == parent) continue;
            if(!vis[i])
            {
                dfs(i,node,adj,tin,low,mark,vis);
                low[node]= min(low[node],low[i]);
                if(tin[node] <= low[i] && parent != -1)
                {
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]= min(low[node],tin[i]);
            }
        }
        if(child > 1 && parent == -1) mark[node] = 1;
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V,0);
        int tin[V];
        int low[V];
        vector<int> mark(V,0);
        vector<vector<int>> adj(V);
        for(auto &i : edges)
        {
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,adj,tin,low,mark,vis);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(mark[i] == 1) ans.push_back(i);
        }
        if(ans.size() == 0) return {-1};
        else return ans;
    }
};
