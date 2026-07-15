// Bismillah Rahman Raheem

#include <bits/stdc++.h>
using namespace std;

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy) {

        // Convert to 0-based indexing
        Sx--; Sy--;
        Fx--; Fy--;

        if (Sx == Fx && Sy == Fy)
            return 0;

        vector<vector<int>> dist(N, vector<int>(N, -1));

        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1,  1, -2,  2,-2, 2,-1, 1};

        queue<pair<int,int>> q;
        q.push({Sx, Sy});
        dist[Sx][Sy] = 0;

        while (!q.empty()) {
            pair<int, int> node = q.front();
            int x = node.first;
            int y = node.second;
            q.pop();

            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
                    dist[nx][ny] == -1) {

                    dist[nx][ny] = dist[x][y] + 1;

                    if (nx == Fx && ny == Fy)
                        return dist[nx][ny];

                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
signed main(){
    ios_base::sync_with_stdio(0);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
    return 0;
}

