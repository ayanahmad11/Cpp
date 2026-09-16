// Bismillah hir-Rahman nir-Rahim;
#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
// vector<int> outdeg;
int n,m;
void kahn(){
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if( indeg[i] == 0)
        {
            q.push(-i);
        }
    }
    while(!q.empty()){
        int curr = -q.top();
        q.pop();
        topo.push_back(curr);
            for(auto v:g[curr]){
                indeg[v]--;
                if(indeg[v] == 0)
                    q.push(-v);
            }
    }
}
void solve(){
    
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1,0);
    // outdeg.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
        // outdeg[a]++;
    }
    kahn();
    if(topo.size()!=n)
    cout<<"There is a cycle"<<endl;
   
    for(auto e:topo)
        cout<<e<<" ";
    
    cout<<endl;


}
signed main(){
int T = 1;
// cin>>T;
while(T--)
    solve();
}
/*
Algorithm Steps:

1>Compute the indegree of each vertex in the graph.
2>Initialize a queue and enqueue all vertices with an indegree of 0.
3>Dequeue a vertex, output it, and reduce the indegree of its neighbors.
4>Repeat steps 3-4 until the queue is empty.
*/