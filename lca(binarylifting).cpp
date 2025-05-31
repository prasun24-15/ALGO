#include<bits/stdc++.h>
using namespace std;
const int LOG=15;
const int max_n=100000;
vector<int> depth(max_n, 0);
vector<int> children[max_n];

int up[max_n][LOG];
void dfs(int a)
{
    for(int b: children[a])
    {
        depth[b]=depth[a]+1;
        up[b][0]=a;
        for(int j=1; j<LOG; j++)
        {
            up[b][j]=up[up[b][j-1]][j-1];
        }
        dfs(b);
    }
    
}
int lca(int a,int b)
{
    if(depth[a]<depth[b])
    {
        swap(a, b);
    }
    int k=depth[a]-depth[b];
    for(int i=0; i<LOG; i++)
    {
        if(k&(1<<i))
        {
            a=up[a][i];
        }
    }
    if(a==b)
    {
        return a;
    }
    for(int i=LOG-1; i>=0; i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int children_count;
        cin>>children_count;
        for(int j=0; j<children_count; j++)
        {
            int child;
            cin>>child;
            children[i].push_back(child);
        }
    }
    up[0][0] = 0;
    dfs(0);
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int a, b;
        cin>>a>>b;
        cout<<lca(a, b)<<endl;
    }

    
}
