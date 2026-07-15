// Bismillah Rahman Raheem
/*
Zenithland has n cities and m roads between them.
The goal is to construct new roads so that there is a route between any two cities.
A road is bidirectional.
Your task is to find out the minimum number of roads required.
Hint:[Find the number of connected components.]
*/
#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

vector<vector<int>> g;
vector<int> vis;
void dfs(int node)
{
    vis[node] = 1;
    for(auto v:g[node]){
        if(!vis[v])
        {
            dfs(v);
        }
    }
}
void solve(){

    int n,m;
    cin>>n>>m;

    g.resize(n+1);
    vis.resize(n+1);

    while(m--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int num_comp = 0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]){
            dfs(i);
            cout<<"node"<<" "<<i<<endl;
            num_comp++;
        }
    }
    cout<<num_comp-1<<endl;
}
signed main(){
    int tt = 1;
    // cin>>tt;
    while(tt--){
        solve();
    }
}
