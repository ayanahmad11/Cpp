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
int dp[100100]; 
int rec(int node){ //longest path starting at node.
    if(dp[node]!=-1) return dp[node]; 
    int ans = 1;
    for(auto x:g[node]){
        ans = max(ans,1+rec(x));
    }
    return dp[node] = ans;
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
    memset(dp,-1,sizeof(dp));
    int ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        ans = max(ans,rec(i));
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {  dfs(i);
        }
    }
    // reverse(topo.begin(),topo.end());
    // for(auto e:topo)
    // {
    //     cout<<e<<" ";
    // }
    // cout<<endl;
    
    // Dfs way of topological ordering.
    int final = 0;
    for(auto node:topo)
    {
        int ans = 1;
        for(auto v:g[node]){
            ans = max(ans,1+dp[v]);
        }
        dp[node] = ans;
        final = max(final,dp[node]);
    }
    cout<<final<<endl;
}
signed main(){
    int T = 1;
    // cin>>T;
    while(T--)
        solve();
}
