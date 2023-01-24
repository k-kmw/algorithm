#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];
int dist[1001][1001][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            fill(dist[i][j], dist[i][j]+2, -1);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    queue<pair<pair<int, int>, int>> q;
    dist[0][0][0] = 1;
    q.push({{0, 0}, 0});
    while(!q.empty()) {
        auto cur = q.front();
        if(cur.first.first == n-1 && cur.first.second == m-1) {
            cout << dist[n-1][m-1][cur.second];
            return 0;
        }
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first.first + dx[dir];
            int ny = cur.first.second + dy[dir];
            int broken = cur.second;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)  continue;
            if(dist[nx][ny][broken] != -1)  continue;
            if(board[nx][ny] == '1' && broken != 1 && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[cur.first.first][cur.first.second][0] + 1;
                q.push({{nx, ny}, 1});
            }
            if(board[nx][ny] == '0') {
                dist[nx][ny][broken] = dist[cur.first.first][cur.first.second][broken] + 1;
                q.push({{nx, ny}, broken});
            }
        }
    }
    cout << -1;

}


