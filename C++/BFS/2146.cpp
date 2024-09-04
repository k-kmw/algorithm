#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int vis[101][101];
int dist[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    int cnt = 0;
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == 0 || vis[i][j])   continue;
            cnt++;
            vis[i][j] = 1;
            board[i][j] = cnt;
            q.push({i, j});
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >=n || ny < 0 || ny >= n)   continue;
                    if(vis[nx][ny] || board[nx][ny] == 0)   continue;
                    vis[nx][ny] = 1;
                    board[nx][ny] = cnt;
                    q.push({nx, ny});
                }
            }
        }
    }
//    for(int i=0; i<n; i++) {
//        for(int j=0; j<n; j++)
//            cout << board[i][j];
//        cout << '\n';
//    }

    for(int i=0; i<n; i++)
        fill(dist[i], dist[i]+n, -1);

    int ans = 205;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] != 0) {
                dist[i][j] = 0;
                q.push({i, j});
                bool escape = false;
                while(!q.empty() && !escape) {
                    auto cur = q.front();
                    q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n)  continue;
                        if(dist[nx][ny] >= 0 || board[i][j] == board[nx][ny]) continue;
                        if(board[nx][ny] != 0 && board[i][j] != board[nx][ny]) {
                            ans = min(ans, dist[cur.first][cur.second]);
                            while(!q.empty())   q.pop();
                            escape = true;
                            break;
           }
                        dist[nx][ny] = dist[cur.first][cur.second] + 1;
                        q.push({nx, ny});
                    }
                }
            }
            for(int i=0; i<n; i++)
                fill(dist[i], dist[i]+n, -1);
        }
    }
    cout << ans;

}


