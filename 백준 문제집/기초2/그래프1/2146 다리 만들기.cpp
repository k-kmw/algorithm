#include <bits/stdc++.h>
using namespace std;
int n;
int board[105][105];
bool vis[105][105];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int num = 1;
queue<pair<pair<int, int>, pair<int, int>>> q2; // y, x, 섬의 번호, 거리

void bfs(int i, int j) {
    queue<pair<int,int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(vis[ny][nx] || board[ny][nx] == 0) continue;
            vis[ny][nx] = true;
            board[ny][nx] = num;
            q.push({ny, nx});
            q2.push({{ny, nx}, {board[ny][nx], 0}});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. bfs 돌면서 섬찾기 - 번호 매기기
    // 2. 각 섬의 모든 점을 큐에 넣기
    // 3. 인접이 바다이면 다른 번호의 섬 만날때 까지 계속 탐색
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] != 0 && !vis[i][j]) {
                board[i][j] = num;
                q2.push({{i, j}, {board[i][j], 0}});
                bfs(i, j);
                num++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    for(int k=0; k<n; k++)
        fill(vis[k], vis[k]+n, false);
    while(!q2.empty()) {
        auto cur = q2.front();
        q2.pop();
        cout << cur.first.first << ' ' << cur.first.second << ' ' << cur.second.first << ' ' << cur.second.second << '\n';
        for(int dir=0; dir<4; dir++) {
            int ny = cur.first.first + dy[dir];
            int nx = cur.first.second + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(board[ny][nx] != 0) continue;
            if(board[ny][nx] != 0 && board[ny][nx] != cur.second.first) {
                cout << cur.second.second << '\n';
                return 0;
            }
            vis[ny][nx] = true;
            q2.push({{ny, nx}, {cur.second.first,cur.second.second+1}});
        }
    }
}