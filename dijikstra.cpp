#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<pair<int,int>>> adj(vertices);
    for(auto i:vec)
    {
        int start=i[0];
        int des=i[1];
        int dis=i[2];
        adj[start].push_back({des,dis});
        adj[des].push_back({start,dis});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[source]=0;
    pq.push({0,source});
    while(!pq.empty())
    {
        auto temp=pq.top();
        int dist1=temp.first;
        int node=temp.second;
        pq.pop();
        for(auto i: adj[node])
        {
            int des1=i.first;
            int extradis=i.second;
            if(dist1+extradis<dist[des1]){
                dist[des1]=dist1+extradis;
                pq.push({dist[des1],des1});
            }
        }
    }
    return dist;
}
