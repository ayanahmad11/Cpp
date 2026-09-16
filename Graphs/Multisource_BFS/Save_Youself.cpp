/* Bismillah hir-Rahman nir-Rahim
You and some monsters are in a matrix. 
When taking a step to some direction in the matrix,
each monster may simultaneously take one as well. 
Your goal is to reach one of the boundary squares without ever
sharing a square with a monster.

Your task is to find out if your goal is possible, 
and if it is, print the shortest length of the path
that you can follow. Your plan has to work in any situation; 
even if the monsters know your path beforehand.

Input Format

The first input line has two integers n and m: the height and width of the matrix.
After this, there are n lines of m characters describing the matrix.
Each character is . (floor), # (wall), A (start), or M (monster).
There is exactly one A in the input.

Output Format

First, print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print the length of the shortest path 
that you'll follow.

Constraints
1≤n,m≤1000

*/
#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
const int N = 1010;

int n,m;
bool grid[N][N];
int distA[N][N];
int distMon[N][N];
pair<int,int> par[N][N];

queue<pair<int,int>> AOccur;
queue<pair<int,int>> MonOccur;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void solve(){
    cin>>n>>m;
    memset(grid, false, sizeof(grid));
    memset(distMon,-1,sizeof(distMon));
    memset(distA,-1,sizeof(distA));


    for(int i=0;i<n;i++)
    {
        string s;  cin>>s;
        for(int j=0;j<m;j++)
        {
            grid[i][j] = true;
            if(s[j] == '#') grid[i][j] = false; 
            else if(s[j]=='A')
            {
                distA[i][j] = 0;
                AOccur.push({i,j});
                par[i][j] = {-1,-1};
            }
            else if(s[j] == 'M')
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
     while(!AOccur.empty()){
        auto it = AOccur.front();
        AOccur.pop();
        int x =  it.first , y = it.second;

            for(int i=0;i<4;i++){
                int xx = x + dx[i] , yy = y + dy[i];
                if(xx<0 || xx>=n || yy < 0 || yy >=m) continue;
                if(grid[xx][yy] && distA[xx][yy] == -1)
                   { distA[xx][yy] = distA[x][y] + 1 ;
                    AOccur.push({xx,yy}); 
                    par[xx][yy] = {x,y};
                    }
            }   
    }
    int finx = -1 , finy = -1, findist =  1e9;
    for(int i=0;i<n;i++){
        if(grid[i][0] && distA[i][0]>=0 && (distA[i][0]< 
        distMon[i][0] || distMon[i][0] == -1)){
            finx = i , finy = 0;
            findist = min(findist,distA[i][0]);  
        }
        if(grid[i][m-1] && distA[i][m-1]>=0 && (distA[i][m-1]< 
        distMon[i][m-1] || distMon[i][m-1] == -1)){
            finx = i , finy = m - 1;
            findist = min(findist,distA[i][m-1]);  
        }   
    }
    for(int i=0;i<m;i++){
        if(grid[0][i] && distA[0][i]>=0 && (distA[0][i]< 
        distMon[0][i] || distMon[0][i] == -1)){
            finx = 0 , finy = i;
            findist = min(findist,distA[0][i]);  
        }
        if(grid[n-1][i] && distA[n-1][i]>=0 && (distA[n-1][i]< 
        distMon[n-1][i] || distMon[n-1][i] == -1)){
            finx = n - 1 , finy = i;
            findist = min(findist,distA[n-1][i]);  
        }   
    }
    if(finx == -1 ) cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
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
