#include<bits/stdc++.h>
// #include"debug.h"
#define int long long
#define endl '\n'
using namespace std;

vector<vector<pair<int,int>>> g;
vector<int> dis;
void BFS01(int sc)
{
    deque<int> dq;
    dis[sc] = 0;
    dq.push_back(sc);
    while(!dq.empty())
    {
        
        int x = dq.front();
        dq.pop_front();
        for(auto v:g[x])
        {
            int neigh = v.first;
            int weigh = v.second;
    
            if(dis[neigh] > dis[x] + weigh )
            {
               
                dis[neigh] = dis[x] + weigh;
                if(weigh == 0)
                {
                    dq.push_front(neigh);
                }
                else
                {
                    dq.push_back(neigh);
                }
            }
            
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    int a,b;
    g.assign(n+1,{});
    dis.assign(n+1,1e9);
    map<pair<int,int>,int> mp;
    for(int i=0;i<m;i++)
    {   
        cin>>a>>b;
        if(a == b) continue;
        else if(mp.find({a,b})==mp.end())
        {
            g[a].push_back({b,0});
            g[b].push_back({a,1});
            mp[{a,b}]++;
        } 
    }
    // debug(g); 
    BFS01(1);
    cout<<dis[n]<<endl;
}
signed main(){
    int T;
    cin>>T;
    while(T--)
        solve();
}
