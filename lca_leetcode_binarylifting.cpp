class Solution {
    int LOG = 0;
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;
    vector<int> pow2;
    const int MOD = 1e9 + 7;

private:
    void dfs(int node, int parent) {
        up[node][0] = parent;
        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1)
                up[node][i] = up[up[node][i - 1]][i - 1];
        }
        for (int child : adj[node]) {
            if (child != parent) {
                depth[child] = depth[node] + 1;
                dfs(child, node);
            }
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int k = depth[a] - depth[b];
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                a = up[a][i];
            }
        }
        if (a == b) return a;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[a][i] != -1 && up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        while ((1 << LOG) <= n) LOG++;

        up = vector<vector<int>>(n + 1, vector<int>(LOG, -1));
        depth = vector<int>(n + 1, 0);
        adj = vector<vector<int>>(n + 1);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, -1);
        pow2 = vector<int>(2 * n + 1, 1);
        for (int i = 1; i <= 2 * n; i++) {
            pow2[i] = (1LL * pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;
        for (auto &q : queries) {
            int a = q[0], b = q[1];
            int lca_ = lca(a, b);
            int dist = depth[a] + depth[b] - 2 * depth[lca_];
            ans.push_back(dist == 0 ? 0 : pow2[dist - 1]);
        }
        return ans;
    }
};
