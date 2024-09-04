#include <bits/stdc++.h>
using namespace std;

int dist[105][105]; // (i, j)에서 부순 벽의 최소 개수
bool vis[105][105];
int board[105][105];
priority_queue< pair<int, pair<int, int> > > pq; // 부순 벽의 최소 개수, 좌표
int n, m;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int main() {
    cin >> m >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            char x;
            cin >> x;
            board[i][j] = x - '0';
        }
    }

    for(int i=1; i<=n; i++) {
        fill(dist[i]+1, dist[i]+1+m, 100*101);
    }

    dist[1][1] = 0;
    pq.push(make_pair(0, make_pair(1, 1)));

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int y = cur.second.first;
        int x = cur.second.second;
//        cout << y << ' ' << x << '\n';
        if(vis[y][x]) continue;

        vis[y][x] = true;

        for(int dir=0; dir<4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny <= 0 || ny > n || nx <= 0 || nx > m) continue;
            if(vis[ny][nx]) continue;
            if(board[ny][nx] == 1) {
                if(dist[ny][nx] > dist[y][x] + 1) {
                    dist[ny][nx] = dist[y][x] + 1;
                    pq.push(make_pair(-dist[ny][nx], make_pair(ny, nx)));
                }
            } else if(board[ny][nx] == 0) {
                if(dist[ny][nx] > dist[y][x]) {
                    dist[ny][nx] = dist[y][x];
                    pq.push(make_pair(-dist[ny][nx], make_pair(ny, nx)));
                }
            }
        }
    }
    cout << dist[n][m] << '\n';
}