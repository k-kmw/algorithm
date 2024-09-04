#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int board[501][501];
int vis[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    int mx = 0;
    int num = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            queue<pair<int, int>> q;
            if(board[i][j] && !vis[i][j]) {
                num++;
                q.push({i, j});
                vis[i][j] = 1;
//                cout << i << ' ' << j << '\n';
            }
            else    continue;
            int area = 0;
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                area++;
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)   continue;
                    if(vis[nx][ny] || board[nx][ny] != 1)   continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << num << '\n' << mx;

}