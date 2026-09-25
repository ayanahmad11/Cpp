/*
Bellman-Ford Revisited
Time Limit: 2 secMemory: 256 MB

Description
You are given a graph G with n nodes and m edges. 
Each edge has an integer weight associated with it. 
The weight of an edge may be negative, positive or zero.

If there exists a cycle with total weight>0 that is reachable 
from node 1 ,
and from which node n is reachable, print −1.

Otherwise, find the maximum possible path weight 
from node 1 to node n.

Input Format
The first input line has two integers n and m: the number of nodes 
and edges. The nodes are numbered 1,2,…,n.

Then, there are m lines describing the edges.

Each line has three integers a, b and x: 
the edge starts at node a, ends at node b,
and the weight of the edge is x.

All edges are unidirectional. 
You can assume that it is possible to get from node 1 to node n.

Output Format
Print the answer on a new line.

Constraints
1≤n≤2500
1≤m≤5000
1≤a,b≤n
−109≤x≤109

*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, wt;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (auto &e : edges) {
        cin >> e.u >> e.v >> e.wt;
        e.wt = -e.wt;
    }

    int src;
    cin >> src;

    const long long INF = 1e18;
    vector<long long> dist(n + 1, INF);

    dist[src] = 0;

    // V - 1 relaxation rounds
    for (int i = 1; i <= n - 1; i++) {

        bool changed = false;

        for (auto e : edges) {

            // u is unreachable
            if (dist[e.u] == INF)
                continue;

            if (dist[e.u] + e.wt < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.wt;
                changed = true;
            }
        }

        // Optional optimization
        if (!changed)
            break;
    }

    // One extra round to detect negative cycle
    bool negativeCycle = false;

    for (auto e : edges) {
        if (dist[e.u] != INF &&
            dist[e.u] + e.wt < dist[e.v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        // cout << "Negative Cycle\n";
        cout<<-1<<endl;
    } else {
            cout<<-dist[n]<<endl;
    }

    return 0;
}
/*
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4  
output = 5
5 4
1 5 3
2 4 -1
4 5 5
4 2 2
output = 3
*/