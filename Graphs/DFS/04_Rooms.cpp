/*
Find the Number of Rooms
Solved
Time Limit: 2 sec
Memory: 256 MB
Description
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is 
n×m squares, and each square is either floor or wall.
You can walk left, right, up, and down through the floor squares. 
Each character in the map is either 
'.'   (floor) or '#' (wall).

Defination of Room : A maximal connected group of floor cells (.), where connectivity is only through up, down, left, or right moves.
Input Format
The first input line has two integers 
n and m
m: the height and width of the map. Then there are 
n lines of 
m characters describing the map.

Output Format
Print one integer: the number of rooms.

Constraints
1≤n,m≤1000
*/
#include<bits/stdc++.h>
// #include"debug.h"
#define F first
#define S second
#define int long long
using namespace std;
int n,m;
// vector<vector<int>> g;
vector<string> g;
vector<vector<int>> vis;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool check(int x,int y){
    
    if(x>=0 && x<n && y>=0 && y<m && g[x][y]!='#')
    {
        return 1;
    }
    return 0;
}
vector<pair<int,int>> neighbours(pair<int,int> node){
    vector<pair<int,int>> neighs;
    for(int k=0;k<4;k++)
    {
        int x = node.F + dx[k];
        int y = node.S + dy[k];
        if(check(x,y))
        {
            neighs.push_back({x,y});
        }
    }
    return neighs;
}
void dfs(pair<int,int> node){
    vis[node.F][node.S] = 1;
    for(auto x:neighbours(node)){
        if(!vis[x.F][x.S])
        {
            dfs(x);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        g.push_back(s);
    }
    vis.assign(n,vector<int>(m));
    // debug(vis);
    int comp = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(g[i][j] == '.' && !vis[i][j])
           {  dfs({i,j});
              comp++;
           }
        }
    }
    // debug(g);
    // debug(comp);
    cout<<comp<<endl;
}

signed main(){
    int T = 1;
    // cin>>T;
    while(T--)
        solve();
}
/*
5 8
########
#..#...#
####.#.#
#..#...#
########
ans-3
*/