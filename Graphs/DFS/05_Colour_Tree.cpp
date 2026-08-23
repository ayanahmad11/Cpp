/*
Description

You have been given a tree with N nodes and N−1 edges. 
You want to colour each node, such that no two adjacent nodes
(directly connected by an edge) and no two nearly-adjacent nodes
(both directly connected to a common node with edges) has the same colour. 
Your task is to find the minimum number of colours required to accomplished this.

Input Format

The first line of input contains N.
Each of the remaining N−1 lines describes an edge in terms of the two nodes it connects.

Output Format
Print the minimum number of colours required.

Constraints
1≤N≤105
*/
#include<bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a,b;
    vector<int> t(n);
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        t[--a]++;t[--b]++;
    }
    int D = -1;
    for(int i=0;i<n;i++)
    {
        //maximum indegree 
        D = max(D,t[i]);
    }
    cout<<D+1<<endl;
}
signed main(){
    int tt = 1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}
/*
4
1 2
4 3
2 3
output - 3
*/