#include <bits/stdc++.h>
// #include"debug.h"
#define int long long 
using namespace std;

vector<vector<int>> g;
vector<int> visited;
void dfs(int node,int col)
{
    visited[node] = col;
    for(auto x:g[node])
    {
        if(!visited[x])
        {
            dfs(x,col);
        }
    }
}
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    g.assign(n+1,vector<int>());
    visited.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int col = 1 , num_comp = 0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i,col);
            num_comp++;
            col++;
            // cout<<i<<" "<<num_comp<<endl;
        }
    }
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        // cout<<visited[i]<<" ";
        mp[visited[i]]++;  
    }
    // debug(mp);
    // cout<<num_comp<<endl;
    while(q--)
    {
        int r,x,y;
        cin>>r;
        if(r == 1)
        {
            cin>>x;
            
            cout<<mp[visited[x]]<<endl;
        }
        else{
            cin>>x>>y;
            if(visited[x] == visited[y])
            {
                cout<<"YES"<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
        
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