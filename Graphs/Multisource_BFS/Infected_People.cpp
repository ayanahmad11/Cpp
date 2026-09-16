/* Bismillah hir-Rahman nir-Rahim*/
#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
const int N = 1010;

int n,m;
bool grid[N][N];
// int distA[N][N];
int distMon[N][N];
// pair<int,int> par[N][N];

vector<pair<int,int>> AOccur;
queue<pair<int,int>> MonOccur;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void solve(){
    cin>>n>>m;
    memset(grid, false, sizeof(grid));
    memset(distMon,-1,sizeof(distMon));
    // memset(distA,-1,sizeof(distA));

    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
            grid[i][j] = true;
            if(v[i][j] == 0) grid[i][j] = false; 
            else if(v[i][j]==1)
            {
               AOccur.push_back({i,j});
            }
            else if(v[i][j] == 2)
            {
                distMon[i][j] = 0;
                MonOccur.push({i,j});
            }
        }
    }
    while(!MonOccur.empty()){
        auto it = MonOccur.front();
        MonOccur.pop();
        int x =  it.first , y = it.second;

            for(int i=0;i<4;i++){
                int xx = x + dx[i] , yy = y + dy[i];
                if(xx<0 || xx>=n || yy < 0 || yy >=m) continue;
                if(grid[xx][yy] && distMon[xx][yy] == -1)
                   { distMon[xx][yy] = distMon[x][y] + 1 ;
                     MonOccur.push({xx,yy}); 
                    }
            }   
    }
    if(AOccur.size() == 0)
    {
        cout<<0<<endl;
        return;
    }
    int findist = -1;
    bool f = true; 
    for(int i=0;i<AOccur.size();i++){
        int x = AOccur[i].first;
        int y = AOccur[i].second;
        if(distMon[x][y] == -1)
        {
            f = false;
            break;
        }
        else
        {
            findist = max(findist, 1LL * distMon[x][y]) ;
        }
    }
    if(!f) cout<<-1<<endl;
    else
    {
        // cout<<"Yes"<<endl;
        cout<<findist<<endl;
          /*****************************************
        ----PRINTING PATH---
        string path = "";
        int x = finx, y = finy;
        while(true) {
            int prex = par[x][y].first;
            int prey = par[x][y].second;
            if(prex == -1 && prey == -1) break;
            if(y - prey == 1) path += 'R';
            else if(y - prey == -1) path += 'L';
            else if(x - prex == 1) path += 'D';
            else path += 'U';
            x = prex; y = prey;
        }
        reverse(path.begin(), path.end());
        cout << path << "\n";
        ******************************************/
    }


}
signed main(){
    int T = 1;
    // cin>>T;
    while(T--)
        solve();
}
// Problem with MSSP on healthy peeps:
/*
2 1 1
1 1 2 would give time 1
but ans is 2
*/