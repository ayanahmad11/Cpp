    #include<bits/stdc++.h>
    #include"debug.h"
    using namespace std;
    #define F first
    #define S second
    int n,m;
    vector<vector<int>> g;
    vector<vector<int>>dis;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};


    bool check(int x, int y){
        if(x >= 0 && x < n && y >= 0 && y < m){
            return true;
        }                // boundary or empty cell contributes to perimeter
        return false;
    }
    vector<pair<int,int>> neighbours(pair<int,int> node){
        vector<pair<int,int>> neighs;

        for(int k = 0; k < 4; k++){
            int x = node.F + dx[k];
            int y = node.S + dy[k];

            if(check(x, y)){
                neighs.push_back({x, y});
            }
        }

        return neighs;
    }
    int get(pair<int,int> xx,pair<int,int> l){
            if(g[xx.F][xx.S] == 1 && (l.first == xx.F && l.second == xx.S+1))
            {
                    return 0;
            }
            else if (g[xx.F][xx.S] == 2 &&(l.first == xx.F && l.second == xx.S-1) )
            {
                    return 0;
            }
            else if (g[xx.F][xx.S] == 3 && (l.first == xx.F+1 && l.second == xx.S))
            {
                return 0;
            }
            else if(g[xx.F][xx.S] == 4 && (l.first == xx.F-1 && l.second == xx.S))
            {       
                return 0;
            }
            return 1;
    }
    void BFS01(pair<int,int> sc){

        deque<pair<int,int>> dq; 
        dis.assign(n, vector<int>(m, 1e9));

        dis[sc.first][sc.second] = 0;
        dq.push_back(sc);

        while(!dq.empty())
        {
            auto xx = dq.front();
            dq.pop_front();
            vector<pair<int,int>> neigs = neighbours(xx);
            for(auto l:neigs)
            {
            int neigh_x = l.first;
            int neigh_y = l.second;
            int weigh = get(xx,l);
            if(dis[neigh_x][neigh_y]>dis[xx.F][xx.S] + weigh)
            {
                    dis[neigh_x][neigh_y] = dis[xx.F][xx.S] + weigh;
                    if(weigh == 0)
                    {
                        dq.push_front({neigh_x,neigh_y});
                    }
                    else
                    {
                        dq.push_back({neigh_x,neigh_y});
                    }
            }
            }

    
        //     for(int k = 0; k < 4; k++){
        //     int x = xx.F + dx[k];
        //     int y = xx.S + dy[k];
        //     // if(g[x][y] == ) how will i ddecide 0/1 bfs here
        //     if(check(x, y)){ // within the grid;
        //         if(g[xx.F][xx.S] == 1)
        //         {
                    
        //         }
        //     }
        // }
            
        }
    
    }
    void solve(){
        cin>>n>>m;
        g.assign(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
            cin>>g[i][j];
            }
        }
        int sc;
        cin>>sc;
        debug(g);
        BFS01({0,0});
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout<<dis[n-1][m-1]<<" ";
        cout<<endl;
    }
    signed main(){
        int T;
        cin>>T;
        while(T--)
            solve();
    }