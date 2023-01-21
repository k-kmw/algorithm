#include <bits/stdc++.h>
using namespace std;

char board[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    vis[i][j] = true;
    q.push({i, j});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n)   continue;
            if(vis[nx][ny] || board[cur.first][cur.second] != board[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    int cnt_nrg = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!vis[i][j]) {
                bfs(i, j);
                cnt_nrg++;
            }
        }
    }

    for(int i=0; i<n; i++)
        fill(vis[i], vis[i]+n, false);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == 'R')  board[i][j] = 'G';
        }
    }

    int cnt_rg = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!vis[i][j]) {
                bfs(i, j);
                cnt_rg++;
            }
        }
    }
    cout << cnt_nrg << ' ' << cnt_rg;
}


