// Bismillah Rahman Rahim
#include<bits/stdc++.h>
// #include "debug.h"
#define int long long
#define endl '\n'
#define INF 1e9
#define F first
#define S second
using namespace std;

int n,m;// variable for nodes and edges 
vector<vector<pair<int,int>>> g; //  graph 
vector<int> vis; // vector to check if node is visited
vector<int> dis;// vector to calculate the distance from single source

void dijkstra(int sc)
{
    vis.assign(n+1,0);
    dis.assign(n+1,INF);
    priority_queue<pair<int,int>> q;  // pair<dist,nodeNo>

    dis[sc] = 0; // distance for source node is 0
    q.push({0,sc}); // inserting source node in priority queue

    while(!q.empty())
    {
        int x = q.top().S;
        q.pop();

        if(vis[x]) continue;
        vis[x] = 1;

        for(auto v:g[x])
        {
            if(dis[v.F] > (dis[x] + v.S))
            {
                dis[v.F] = dis[x] + v.S;
                q.push({-dis[v.F],v.F});
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    g.resize(n+1);// resisizing graph for n nodes
    // Input for m edges
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    // Input for source node
    int sc;
    cin>>sc;
    // function for sssp
    dijkstra(sc);
    for(int i=1;i<=n;i++)
    {   
        cout<<dis[i]<<" "; 
    }
}
signed main(){
    int tt=1;
    // cin>>tt;
    while(tt--)
    {
        solve();
    }
}
