/*
Area and Perimeter of Connected Components

Description
You have been given a grid of size N×N.
Each cell is either empty (.) or occupied (#).
Size of each cell is 1×1. In a connected component,
you can reach any cell from every other cell in the 
component by repeatedly stepping to adjacent cells in 
the north, south, east, and west directions. 
Your task is to find the area and perimeter of the
connected component having the largest area. 
The area of a connected component is the number of # 
characters that are part of it. If multiple connected 
components tie for the largest area, 
find the smallest perimeter among them.

Input Format

The first line of input contains N,
and the next N lines describe the grid. 
At least one # character will be present.

Output Format

Please output one line containing two space-separated integers,
the first being the area of the largest connected component,
and the second being its perimeter. If multiple connected components
tie for the largest area, print the one which has the smallest perimeter
among them.

Constraints
1≤N≤1000

*/
#include <bits/stdc++.h>
#define F first
#define S second
#define int long long

using namespace std;

int n, m;
vector<string> g;
vector<vector<int>> vis;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int area = 0, p = 0;

bool check(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '#'){
        return true;
    }
    p++;                // boundary or empty cell contributes to perimeter
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

void dfs(pair<int,int> node, int col){

    vis[node.F][node.S] = col;
    area++;
    for(auto x : neighbours(node)){
        if(!vis[x.F][x.S]){
            dfs(x, col);
        }
    }

}

void solve(){
    cin >> n;
    m = n;

    g.clear();
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        g.push_back(s);
    }

    vis.assign(n, vector<int>(m, 0));
    int bestArea = 0, bestPeri = 0;
    int col = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '#' && !vis[i][j]){

                area = 0;
                p = 0;

                dfs({i, j}, col);
                col++;

                if(area > bestArea){
                    bestArea = area;
                    bestPeri = p;
                }
                else if(area == bestArea && p < bestPeri){
                    bestPeri = p;
                }
            }
        }
    }
    cout << bestArea << " " << bestPeri << endl;
}

signed main(){
    int T = 1;
    while(T--){
        solve();
    }
}