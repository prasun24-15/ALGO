class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin,
             vector<int>& low, vector<vector<int>>& bridges,
             vector<vector<int>>& adj) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for (auto& i : adj[node]) {
            if (i == parent)
                continue;
            if (vis[i] == 0) {
                dfs(i, node, vis, tin, low, bridges, adj);
                low[node] = min(low[node], low[i]);
                if (tin[node] < low[i]) {
                    bridges.push_back({node, i});
                }
            } else {
                low[node] = min(low[node], low[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& i : connections) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        vector<int> tin(n, 0), low(n, 0);
        vector<vector<int>> bridges;
        dfs(0, -1, vis, tin, low, bridges, adj);
        return bridges;
    }
};
