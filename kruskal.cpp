class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<pair<int, pair<int,int>>> edges;
        
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                edges.push_back({wt, {i, adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        int mstWt = 0;
        
        for(auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUparent(u) != ds.findUparent(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mstWt;
    }
};
