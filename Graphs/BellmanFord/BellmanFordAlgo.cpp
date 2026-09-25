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
        cout << "Negative Cycle\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
    }

    return 0;
}