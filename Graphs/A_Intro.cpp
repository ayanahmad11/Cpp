#include <bits/stdc++.h>
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
    int n,m;
    cin>>n>>m;
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
    for(int i=1;i<=n;i++)
    {
        cout<<visited[i]<<" ";  
    }
    cout<<endl;
    cout<<num_comp<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(visited[a] == visited[b])
        {
            cout<<"Same component"<<endl;
        }
        else
        {
            cout<<"Different component"<<endl;
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