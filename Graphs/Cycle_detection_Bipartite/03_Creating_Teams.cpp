/*Creating Teams

Solved
Time Limit: 1 secMemory: 256 MB

Description
There are n students in the AlgoZenith course and m friendships between them.
Your task is to divide the students into two teams in such a way that no two students in a team are friends. 
You can freely choose the sizes of the teams. The size of each team should be positive.

Input Format
The first input line has two integers n and m: 
the number of students and friendships.
The students are numbered 1,2,…,n. 
Then, there are m lines describing friendships.
Each line has two integers a and b: students a and b are friends.
Every friendship is between two different students.
You can assume that there is at most one friendship between any two students.

Output Format
Print YES if it's possible to divide students in two teams, otherwise print NO.

Constraints
1≤n≤105 0≤m≤2×105 1≤a,b≤n

Sample Input 1
5 3 1 2 1 3 4 5

Sample Output 1
YES

Sample Input 2
4 3 1 2 2 3 1 3

Sample Output 2
NO

Note
For the first sample, one possible division is teams {1,4,5} and {2,3} — no two students in the same team are friends, so the answer is YES. For the second sample, the triangle between students 1,2,31,2,3 makes it impossible to split them into two teams without friends appearing in the same team, so the answer is NO.
*/
/*
* Solution : 
* It's not about the previous neighbor's color. It's about the current node and its neighbor having the same color.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> g;
vector<int> color;
bool ok = true;

void dfs(int node, int c) {
    color[node] = c;

    for (auto x : g[node]) {
        if (color[x] == -1) {
            dfs(x, c ^ 1);   // alternate 0 and 1
        } else if (color[x] == c) {
            ok = false;       // same color on adjacent nodes
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    g.assign(n + 1, {});
    color.assign(n + 1, -1);
    ok = true;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1)
            dfs(i, 0);
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

signed main() {
    solve();
}
/*
* Note: A bipartite graph is a graph whose vertices can be divided into two disjoint sets, say A and B, such that every edge connects a vertex in set A to a vertex in set B. If the graph is bipartite, we can divide the students into two teams by assigning one team to set A and the other team to set B.

A bipartite graph is a graph whose vertices can be divided into two disjoint groups such that every edge connects a vertex from one group to a vertex in the other group. No edge connects two vertices within the same group.

Think of it as coloring every vertex with one of two colors.
Every edge must connect a red vertex to a blue vertex.
No edge is allowed between two reds or two blues.


* Solution:
We build an undirected graph with 
n vertices and m edges representing friendships. The problem reduces to checking whether this graph is bipartite. We maintain a color array 
par initialized with −1 (meaning uncolored).

For every uncolored vertex we run a DFS and color the starting vertex with 0, then assign alternating colors 0 and 1 to neighbors. 
If we ever encounter a vertex already colored with a color that conflicts with the required color, the graph is not bipartite and the answer is NO. 

If all connected components are colored without conflict, the graph is bipartite and the answer is YES. The provided editorial code implements exactly this approach.

* Time Complexity per test case: 
O(n+m) because each vertex and edge is processed a constant number of times during DFS.

* Space Complexity per test case: 
O(n+m) to store the adjacency lists and the color array.
*/