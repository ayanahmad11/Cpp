/*
Easy Graph Queries
Solved
Time Limit: 1 secMemory: 256 MB

Description
You are given an undirected graph G with N nodes and M edges. 
You have to answer Q queries. Each query is one of the following two types.

Type 1:  1 X — print the size of the connected component containing node X.
Type 2:  2 X Y — print YES if nodes X and Y are in the same connected component, otherwise print NO.

Note : Use Fast I/O for java code

Input Format

The first line contains three space-separated integers N,  M,  Q.
The next M lines each contain two integers u,  v denoting an undirected edge between nodes u and v.

Each of the next QQ lines contains a single query in one of the formats:

1 X
2 X Y

Output Format
Print Q lines as the answers to the Q queries, each on a new line.

Constraints
1≤N,M,Q≤105
*/

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
/*
6 5 5
1 2
2 3
1 3
4 4
5 6
1 2
1 4
2 3 4
1 5
2 5 6
----
3
1
NO
2
YES
*/