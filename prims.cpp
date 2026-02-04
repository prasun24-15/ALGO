class Solution {
  public:
    typedef pair<int,int> pii;

    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pii>> adjMat(V);

        for(auto &i : edges) {
            adjMat[i[0]].push_back({i[1], i[2]});
            adjMat[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> visited(V, 0);

        int cost = 0;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto topi = pq.top();
            pq.pop();

            int wt = topi.first;
            int node = topi.second;

            if(visited[node]) continue;

            visited[node] = 1;
            cost += wt;

            for(auto &i : adjMat[node]) {
                if(!visited[i.first]) {
                    pq.push({i.second, i.first});
                }
            }
        }
        return cost;
    }
};
