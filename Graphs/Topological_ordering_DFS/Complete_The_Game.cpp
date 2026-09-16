//Bisimillah hir-Rahman nir-Rahim
#include<bits/stdc++.h>
#define int long long 
int mod = 1e9+7;
using namespace std;

vector<vector<int>> g;
vector<int> vis;
vector<int> topo;

int n,m;
int ans = 0;
void dfs(int node){
    vis[node] = 1;    
    for(auto x:g[node]){
        if(!vis[x])
        dfs(x);
    }
    topo.push_back(node);
}
void solve(){
    
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
    //.. dp[u] = number of ways to reach node u from node 1.
    /* DP Transition
        dp[v] += dp[u]
        Every way to reach u creates one corresponding way to reach v.
    */
    vector<int> dp(n+1,0);
    dp[1] = 1;
    for(auto u:topo){
    for(auto v:g[u]){
        dp[v]+=dp[u];
        dp[v]%=mod;
    }
}
    // for(auto e:topo)
    // {
    //     cout<<e<<" ";
    // }
    // cout<<endl;
    cout<<dp[n]<<endl;
}
signed main(){
    int T = 1;
    // cin>>T;
    while(T--)
        solve();
}
