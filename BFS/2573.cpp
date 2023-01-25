#include <bits/stdc++.h>
using namespace std;

int board[300][300];
int height[300][300];
bool vis[300][300];
bool vis2[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cin >> board[i][j];
    }

    int year = 0;
    int cnt = 0;
    while(cnt <= 1) {
        cnt = 0;
        year++;

        // 얼음 녹이는 부분
        queue<pair<int, int>> q;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                height[i][j] = board[i][j];
                if(board[i][j] == 0) continue;
//                cout << height[i][j] << ' ';
                q.push({i, j});
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis2[nx][ny])    continue;
                        if (board[nx][ny] == 0 && height[cur.first][cur.second] > 0) {
                            height[cur.first][cur.second]--;
                            continue;
                        }
                        else if(board[nx][ny] != 0) {
                            vis2[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        //board를 최신 높이로 갱신
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                board[i][j] = height[i][j];

        for(int i=0; i<n; i++) {
            for (int j = 0; j < m; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        return 0;

        // 얼음이 분리 되었는지 확인하는 부분
        queue<pair<int, int>> q2;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if(board[i][j] == 0 || vis[i][j])   continue;
                cnt++;
                if(cnt >= 2)    break;
                cout << cnt << ' ';
                vis[i][j] = true;
                q2.push({i, j});
                while (!q2.empty()) {
                    auto cur = q2.front();
                    q2.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n-1 || ny < 0 || ny >= m-1)  continue;
                        if(vis[nx][ny] || board[nx][ny] == 0) continue;
                        vis[nx][ny] = true;
                        q2.push({nx, ny});
                    }
                }
            }
            if(cnt >= 2)    break;
        }
    }
    cout << year;
}

// 못품


