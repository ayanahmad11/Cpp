// Bismillah rahman raheem
#include <bits/stdc++.h>
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

//.. Edge wait are either 0 and 1


void sssp(int sc)
{
    vis.assign(n+1,0);
    dis.assign(n+1,INF);
    deque<int> q;

    dis[sc] = 0;
    q.push_back(sc);

    while(!q.empty())
    {
        int x = q.front();
        cout<<"node"<<x<<endl;
        q.pop_front();

        if(vis[x]) continue;
        vis[x] = 1;

        for(auto v:g[x])
        {
            cout<<"v"<<v.F<<" "<<v.S<<endl;
            int neigh = v.F;
            int cost = v.S;
            if(dis[neigh] > dis[x]+cost){
                
                dis[neigh] = dis[x] + cost;
                if(cost == 0)
                {
                    q.push_front(neigh);
                }
                else
                {   
                    q.push_back(neigh);
                }
            }       
        }
    }
}
void solve(){
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
    sssp(sc);
    for(int i=1;i<=n;i++)
    {   
        cout<<i<<" "<<dis[i]<<endl; 
    }

}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int tt = 1;
    // cin>>tt;
    while(tt--)
    {
        solve();
    }
}