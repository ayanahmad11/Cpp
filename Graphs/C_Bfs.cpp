//Bismillah rahman raheem 
#include<bits/stdc++.h>
#define int long long
#define end '\n'
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> vis;
vector<int> dis;
void bfs(int src)
{
    queue<int> q;
    vis[src] = 1;
    dis[src] = 0; 
    q.push(src);
    while(!q.empty())
    {
        
        int node = q.front();
        cout<<node<<endl;
        q.pop();
        for(auto v:g[node])
        {
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[node]+1;
                q.push(v);
            }
            
        }
    }
}
/*
6 6
S.#...
..#...
#.#.#.
....#.
####..
F.....
*/
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    int a,b;
    for(int i=0;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n+1,0);
    dis.assign(n+1,1e9);

    bfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<vis[i]<<","<<dis[i]<<endl;
    }

} 
signed main(){
    int tt;
    cin>>tt;
    while(tt--)
    {
        solve();
    }
}
