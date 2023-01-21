#include <bits/stdc++.h>
using namespace std;

int board[52][52];
int vis[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        for(int i=0; i<n; i++) {
            fill(board[i], board[i]+m, 0);
            fill(vis[i], vis[i]+m, 0);
        }
        while(k--) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        queue<pair<int, int>> q;
        int num = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 1 && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({i, j});
                    num++;
//                    cout << i << ' ' << j << '\n';
                }
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m)  continue;
                        if(vis[nx][ny] == 1 || board[nx][ny] == 0)  continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cout << num << '\n';
//        for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) {
//                cout << board[i][j] << ' ';
//            }
//            cout << '\n';
//        }
    }
}


