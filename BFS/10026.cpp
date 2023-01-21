#include <bits/stdc++.h>
using namespace std;

string board[101];
bool vis[101][101];
bool vis2[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> board[i];
    }

    int cnt = 0;
    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!vis[i][j]) {
                vis[i][j] = true;
                q.push({i, j});
                cnt++;
            }
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n)  continue;
                    if(board[nx][ny] != board[cur.first][cur.second] || vis[nx][ny])   continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    int cnt2 = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!vis2[i][j]) {
                vis2[i][j] = true;
                q2.push({i, j});
                cnt2++;
            }
            while(!q2.empty()) {
                auto cur = q2.front();
                q2.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n)  continue;
                    if(!(board[nx][ny]=='R' && board[cur.first][cur.second]=='G' || board[nx][ny] == 'G' && board[cur.first][cur.second] == 'R' ) && (board[nx][ny] != board[cur.first][cur.second]) || vis2[nx][ny])   continue;
                    vis2[nx][ny] = true;
                    q2.push({nx, ny});
                }
            }
        }
    }
    cout << cnt << ' ' << cnt2;
//    for(int i=0; i<n; i++) {
//        for(int j=0; j<n; j++) {
//            cout << board[i][j];
//        }
//        cout << '\n';
//    }
}


