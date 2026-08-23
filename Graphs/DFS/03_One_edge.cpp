/*
One Edge
Solved
Time Limit: 2 secMemory: 256 MB

Description

You are given an undirected graph with n nodes, and m edges between them.
The nodes are numbered 1,2,…,n;
The goal is to add exactly one edge between two nodes such that the total number of connected components in the graph decreases.
Your task is to find the number of ways to add such an edge.

Input Format
The first input line has two integers nn and mm: the number of nodes and edges. After that, there are mm lines describing the edges. Each line has two integers aa and bb: there is an edge between those nodes. An edge always connects two different nodes, and there is at most one edge between any two nodes.

Output Format
Print the number of ways to add such an edge, described in the statement.

Constraints
1≤n≤1051≤n≤105 1≤m≤2×1051≤m≤2×105 1≤a,b≤n1≤a,b≤n
*/
#include<bits/stdc++.h>
// #include"debug.h"
#define int long long
using namespace std;

vector<vector<int>> g;
vector<int> vis;


void dfs(int node,int color){
    vis[node] = color;
    for(auto x:g[node]){
        if(!vis[x])
        {   
            dfs(x,color);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.assign(n+1,vector<int>());
    vis.assign(n+1,0);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int comp = 0;
    int color = 1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {dfs(i,color++);comp++;}
    }
    // debug(comp);
    // debug(g);
    // for(auto x:vis)
    // cout<<x<<" ";
    // cout<<endl;
    vector<int> mp(comp);
    for(int i=1;i<=n;i++)
    {
        mp[--vis[i]]++;
    }
    // debug(mp);
    if(comp == 1)
    {
        cout<<0<<endl;
    }
    else if(comp == 2)
    {
        cout<<mp[0] * mp[1]<<endl;
    }
    else
    {   
        //.. suffix sum ? 
        vector<int> suff(comp);
        suff[comp-1] = mp[comp-1];
        for(int i  = comp-2;i>=0;i--)
        {
            suff[i] = suff[i+1] + mp[i];
        }
        // debug(suff);
        int ans = 0;
        for(int i=0;i<comp-1;i++){
            ans+=(mp[i] * suff[i+1]);
        }
        cout<<ans<<endl;
    }
}
// 1 -5
// 2 -3
// 3 -4
// 4 -2

signed main(){
    int T = 1;
    // cin>>T;
    while(T--)
        solve();
}
/*
5 4     o = 6
1 2
2 3
1 3
4 5
----
4 3     o = 0
1 2
2 3
3 4
*/