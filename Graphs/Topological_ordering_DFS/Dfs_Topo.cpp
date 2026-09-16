//Bisimillah hir-Rahman nir-Rahim
#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector<vector<int>> g;
vector<int> vis;
vector<int> topo;

void dfs(int node){
    vis[node] = 1;
    for(auto x:g[node]){
        if(!vis[x])
        dfs(x);
    }
    topo.push_back(node);
}
void solve(){
    int n,m;
    cin>>n>>m;
    g.assign(n+1,{});
    vis.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {  dfs(i);
        }
    }
    reverse(topo.begin(),topo.end());
    for(auto e:topo)
    {
        cout<<e<<" ";
    }
    cout<<endl;
}
signed main(){
    int T = 1;
    // cin>>T;
    while(T--)
        solve();
}
/*
Topological ordering (or topological sort) is an ordering of the
vertices of a directed acyclic graph (DAG) such that 
every directed edge goes from an earlier vertex 
to a later vertex.

Simple definition
If there is an edge:
u→v
then u must appear before v in the ordering.
*/