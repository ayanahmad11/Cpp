/*
Round Trip
Solved
Time Limit: 1 secMemory: 256 MB

Description
Zenithland has n cities and m roads between them. 
Your task is to check for the existence of a round trip that begins in a city,
goes through two or more other cities, and finally returns to the starting city.
Every intermediate city on the route has to be distinct.

Input Format

The first input line has two integers n and m: the number of cities and roads.
The cities are numbered 1,2,…,n. Then, there are m lines describing the roads.
Each line has two integers a and b: there is a road between those cities. 
Every road is between two different cities, and there is at most one road between any two cities. 
The roads are undirected.

Output Format
Print YES if such a round trip exists,
otherwise print NO.

Constraints

1≤n≤105  1≤m≤2×105  1≤a,b≤n

Sample Input 1
5 6 1 3 1 2 5 3 1 5 2 4 4 5

Sample Output 1
YES

Sample Input 2
4 3 1 2 1 3 3 4

Sample Output 2
NO

Note
In Sample 1, there exists a cycle (for example, 1→3→5→11→3→5→1), so the answer is YES. In Sample 2, the graph is acyclic, so the answer is NO.
*/
#include<bits/stdc++.h>
#define int long long 
using namespace std;

vector<vector<int>>g;
vector<int> col;
vector<int> parent;
bool cycle_detected = false;
void dfs(int node,int farent){
    col[node] = 2; 
    for(auto x:g[node])
    {
        if(x == farent) continue; //skip edge to parent
        if(col[x] == 1)
        {
            parent[x] = node;
            dfs(x,parent[x]);
        }
        else if(col[x] ==2)
        {
            cycle_detected = true;
            // return ;
        }
    }
    col[node] = 3;
}
void solve(){
   int n,m;
   cin>>n>>m;
   g.assign(n+1,vector<int>());
   col.assign(n+1,1);
   parent.assign(n+1,-1);
   int a,b;
   for(int i=0;i<m;i++)
   {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
   }
    for(int i=1;i<=n;i++)
    {
        if(col[i] == 1)
        dfs(i,parent[i]);
    }
//       for(auto x:g)
//    {
//     for(auto e:x)
//     {
//         cout<<e<<" ";
//     }
//     cout<<endl;
//    }
   if(cycle_detected)
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
}

signed main(){
    int tt = 1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}