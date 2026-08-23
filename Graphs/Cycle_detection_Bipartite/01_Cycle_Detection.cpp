#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> g;
vector<int> col;
vector<int> parent;
vector<int> cntcycle;
vector<int> prefixorder;

bool cycle_detected = false;
int cycle_start = -1, cycle_end = -1;

void dfs(int node, int par){
    col[node] = 2;
    parent[node] = par;

    for(auto x:g[node]){
        // for undirected
        // if(par == x) continue;

        if(col[x] == 1)
        {
            //forward edge
            dfs(x,node);
        }
        else if(col[x] == 2)
        {
            //backward edge
            cout<<"Hi"<<endl;

            if(!cycle_detected)
            {
                cycle_start = x;
                cycle_end = node;
            }

            cycle_detected = true;
            cntcycle[node]++;
            cntcycle[parent[x]]--;
        }
        else if(col[x] == 3)
        {
            // Cross edge
        }
    }

    col[node] = 3;
    prefixorder.push_back(node);
}

void solve(){
    int n,m;
    cin>>n>>m;

    g.assign(n+1,vector<int>());
    col.assign(n+1,1);
    parent.assign(n+1,0);
    cntcycle.assign(n+1,0);

    int a,b;

    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i=1;i<=n;i++)
    {
        if(col[i] == 1)
        {
            dfs(i,0);
        }
    }

    cout<<cycle_detected<<endl;
    // cout<<cycle_start<<endl;
    // cout<<cycle_end<<endl;

    vector<int> cycle;
    if(cycle_detected)
    {
        for(int i = cycle_end;i!=cycle_start;i=parent[i])
        {
            cycle.push_back(i);
        }

        cycle.push_back(cycle_start);
        reverse(cycle.begin(),cycle.end());

        for(auto x:cycle)
        {
            cout<<x<<" ";
        }

        cout<<endl;
    }
    // to find the number of nodes which are part of some cycle
    for(auto v:prefixorder){
        cntcycle[parent[v]]+=cntcycle[v];
    }

    for(auto e:cntcycle){
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