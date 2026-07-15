#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<int>> vis;
vector<int> componentSize;

using state = pair<int,int>;

int cnt;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool is_valid(int x, int y)
{
    return x >= 0 && x < n &&
           y >= 0 && y < m &&
           arr[x][y] == 0;
}

vector<state> neighbours(state node)
{
    vector<state> neighs;

    for(int k = 0; k < 4; k++)
    {
        int x = node.first + dx[k];
        int y = node.second + dy[k];

        if(is_valid(x,y))
            neighs.push_back({x,y});
    }

    return neighs;
}

void dfs(state node, int color)
{
    vis[node.first][node.second] = color;
    cnt++;

    for(auto v : neighbours(node))
    {
        if(!vis[v.first][v.second])
            dfs(v, color);
    }
}

void solve()
{
    cin >> n >> m;

    arr.assign(n, vector<int>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    vis.assign(n, vector<int>(m, 0));

    componentSize.clear();
    componentSize.push_back(0); // dummy (component ids start from 1)

    int color = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 0 && !vis[i][j])
            {
                cnt = 0;
                dfs({i, j}, color);

                componentSize.push_back(cnt == 1 ? 0 : cnt);

                color++;
            }
        }
    }

    // Print answer for every cell
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 0)
                cout << componentSize[vis[i][j]] << " ";
            else
                cout << 1<<" ";
        }
        cout << "\n";
    }
}

signed main()
{
    int tt;
    cin >> tt;

    while(tt--)
        solve();
}
// //Bismillah rahman raheem 
// #include<bits/stdc++.h>
// #define int long long
// #define end '\n'
// #define F first
// #define S second
// const int INF = 100;
// using namespace std;
// /*
// 6 6
// S . # . . .
// . . # . . .
// # . # . # .
// . . . . # .
// # # # # . .
// F . . . . .
// */
// int n,m;
// vector<vector<int>> arr;
// using state  = pair<int,int>;

// vector<vector<int>> vis;
// vector<vector<int>> dis;
// // x+dx , y+dy;
// vector<state> cells;  
// vector<vector<int>> comp_size;
// int cnt = 0;  

// int dx[] = {0,1,0,-1};
// int dy[] = {1,0,-1,0};
// bool is_valid(int x, int y)
// {
//     return x >= 0 && x < n &&
//            y >= 0 && y < m &&
//            arr[x][y] == 0;
// }
// vector<state> neighbours(state node){
//     vector<state> neighs;
//     for(int k=0;k<4;k++)
//     {
//         int x = node.F + dx[k];
//         int y = node.S + dy[k];
//         if(is_valid(x,y))
//         {
//             neighs.push_back({x,y});
//         }
//     }
//     return neighs;
// }   
// void dfs(state node, int col)
// {
//     vis[node.F][node.S] = col;
//     cnt++;
//     cells.push_back(node);
//     for (state v : neighbours(node))
//     {
//         if (!vis[v.F][v.S])
//         {
//             dfs(v, col);
//         }
//     }
// }

// void bfs(state st_node)
// {
//     vis.assign(n,vector<int>(m,0));
//     dis.assign(n,vector<int>(m,INF));

//     queue<state> q;
//     vis[st_node.F][st_node.S]=1;
//     dis[st_node.F][st_node.S]=0;
//     q.push(st_node);

//     while(!q.empty())
//     {
//         state node = q.front();
//         q.pop();
//         for(state v: neighbours(node))
//         {
//             if(!vis[v.F][v.S])
//             {
//                 vis[v.F][v.S] = 1;
//                 dis[v.F][v.S] = dis[node.F][node.S] + 1;
//                 q.push(v);
//             }
//         }
//     }

// }

// void solve(){
//     cin>>n>>m;
//     arr.resize(n);

//     for(int i=0;i<n;i++)
//     {
//          arr[i].resize(m);
//          for(int j=0;j<m;j++)
//          {
//             cin>>arr[i][j];
//          }
//     }

//     vis.assign(n, vector<int>(m, 0));
//     comp_size.assign(n, vector<int>(m, 1));

//     int col = 1, num_comp = 0;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (!vis[i][j] && arr[i][j] == 0)
//             {
//                 cnt = 0;
//                 cells.clear();

//                 dfs({i, j}, col);

//                 // Every cell in this component gets its size
//                 if(cells.size() == 1)
//                 {
//                     for (auto cell : cells)
//                 {
//                     comp_size[cell.F][cell.S] = 0;
//                 }
//                 }
//                 else
//                 {for (auto cell : cells)
//                 {
//                     comp_size[cell.F][cell.S] = cnt;
//                 }}

//                 col++;
//             }
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<comp_size[i][j]<<" ";
//         }
//         cout<<endl; 
//     }
// }
// signed main(){
//     int tt;
//     cin>>tt;
//     while(tt--)
//     {
//         solve();
//     }
// }
