//Bismillah hir-Rahman nir-Rahim 
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

