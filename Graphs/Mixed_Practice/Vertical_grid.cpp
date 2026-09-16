/*
Vertical Grid

Time Limit: 2 secMemory: 256 MB
Description
You have been given a vertical grid of size N×10, and a number K. 
Since it's vertical, gravity shows its effect on it. Each cell in the grid contains 
a ball which has some colour. Colour values can vary between 1 to 9.



Each cell in the grid is represented by a number, cij for cell (i,j). 
If cij=0, then the cell (i,j) is empty. Otherwise, it contains a ball with colour cij.
Each cell is either empty (indicated by a 0), or a ball in one of nine different colours (indicated by characters 1..9). 
Gravity causes balls to fall downward, so there is never a 0 cell below a ball.



Two cells belong to the same connected region if they are directly 
adjacent either horizontally or vertically, and they have the same non-zero colour.
Any time a connected region exists with at least K cells, its balls all disappear, turning into zeros. If multiple such connected regions exist at the same time, they all disappear simultaneously. Afterwards, gravity might cause balls to fall downward to fill some of the resulting cells that became zeros. In the resulting configuration, there may again be connected regions of size at least K cells. If so, they also disappear (simultaneously, if there are multiple such regions), then gravity pulls the remaining balls downward, and the process repeats until no connected regions of size at least K exist.



Given the initial vertical grid, your task is to output a 
final picture of the grid after these operations have occurred.

Input Format
The first line of input contains N and K. The remaining N lines specify the initial state of the vertical grid.
Output Format

Please output N lines, describing a picture of the final vertical grid.

Constraints
1≤N≤100
1≤K≤10N
Input           
6 3
0000000000
0000000300
0054000300
1054502230
2211122220
1111111223

0000000000
0000000000
0000000000
0000000000
1054000000
2254500000

*/
#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
int n,k,comp_size = 0;
int vis[101][11];
int board[101][11];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs_size(int x,int y,int color){
    //   cout<<"Hi"<<endl;
        vis[x][y] = 1;
        comp_size++;
        for(int i=0;i<4;i++)
        {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1>=0 && x1<n && y1>=0 && y1<10 && !vis[x1][y1] && board[x1][y1] ==color)
            {
                dfs_size(x1,y1,color);
            }
        }

}
void dfs_delete(int x,int y,int color){
    //   cout<<"Hi"<<endl;
    board[x][y] = 0;
    for(int i=0;i<4;i++){
        int x1 = x+dx[i];
        int y1 = y+dy[i];
        if(x1>=0 && x1<n && y1>=0 && y1<10 && board[x1][y1] == color)
        {
            dfs_delete(x1,y1,color);
        }
    }
}

void gravity(){
    for(int j=0;j<10;j++){
        int p = n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(board[i][j]!=0)
            {
                swap(board[i][j],board[p][j]);
                p--;
            }
        }
    }
}
void solve(){
    int  i,j,l,x;
    char ch;
    string s,str;
    cin>>n>>k;
    memset(board,0,sizeof(board));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>ch;;
            board[i][j] = ch - '0';
        }
    }
    int flag = 1;
    while(flag) // takes care of fact that one change is possible;
    {
        flag = 0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++)
            {
                if((board[i][j] != 0) && (vis[i][j] == 0))
                {
                    comp_size = 0;
                    dfs_size(i,j,board[i][j]);
                    if(comp_size>=k)
                    {
                        dfs_delete(i,j,board[i][j]);
                        flag = 1;
                    }
                }
            }
         }
        gravity();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++)
        {
            cout<<board[i][j] - 48 + '0';
        }
        cout<<endl;
    }

}
signed main(){
    int T=1;
    // cin>>T;
    while(T--)
        solve();
}
/*
Algorithm 
1> While(at least one deletion of component occurs )
{
        a> what is the size of particular color
        b> if(size>=k)
            convert the color to '0'
        c> Apply gravity to fill the vacant spaceds( 0's which are formed by particular compenents)

}
*/