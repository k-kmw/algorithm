#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int board[1001][1001];
int dist[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1)
                q.push({i, j});
            if(board[i][j] == 0)
                dist[i][j] = -1;
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1 || board[nx][ny] != 0 || board[nx][ny] == -1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(dist[i][j] == -1) {
                cout << "-1";
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}