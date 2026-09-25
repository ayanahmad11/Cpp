    #include<bits/stdc++.h>
    // #include"debug.h"
    #define int long long 
    #define endl '\n'
    #define F first
    #define S second
    using namespace std;
    int n,m;
    vector<vector<pair<int,int>>> g;
    vector<pair<pair<int, int>, int>> edges;

    vector<int> dist;
    vector<bool> vis;
    void djikstra(int sc){
        dist.assign(n+1,1e18);
        vis.assign(n+1,false);
    
        dist[sc] = 0 ;
        priority_queue<pair<int,int>> pq;
        pq.push({0,sc});
        while(!pq.empty()){
            auto it = pq.top();
            int x = it.second;
            pq.pop();

            if(vis[x]) continue;
            vis[x]=1;
            for(auto v:g[x]){
                if(dist[v.F] > dist[x] + v.S ) 
                {
                    dist[v.F] = dist[x] + v.S;
                    pq.push({-dist[v.F],v.F});
                }
            }
        }
    }
    void solve(){
        cin>>n>>m;
        // g.assign(n+1,{});
        g.assign(n+1,{});
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
            edges.push_back({{a,b},c});
        }
        // debug(g);
        int sc;
        cin>>sc;
        // debug(sc);
        djikstra(sc);
        int ans = -1e18;
        for(auto it:edges){
            int u = it.first.first;
            int v = it.first.second;
            int d = it.second;
            ans = max(ans,(dist[u]+dist[v]+d)*5);
        }
        cout<<ans<<endl;
    }
    signed main(){
        int T=1;
        // cin>>T;
        while(T--)
        {
            solve();
        }
    }