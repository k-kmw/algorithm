#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

string board[1001];
int dist[1001][1001];
int dist2[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;
    int r, c;
    cin >> r >> c;
    for(int i=0; i<r; i++)
        cin >> board[i];

    for(int i=0; i<r; i++) {
        fill(dist[i], dist[i]+c, -1);
        fill(dist2[i], dist2[i]+c, -1);
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) {
            if(board[i][j] == 'F') {
                q.push({i, j});
                dist[i][j] = 0;
            }
            if(board[i][j] == 'J') {
                q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c)  continue;
            if(board[nx][ny] == '#' || dist[nx][ny] != -1)  continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    while(!q2.empty()) {
        auto cur = q2.front();
        q2.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << dist2[cur.first][cur.second] + 1;
                return 0;
            }
            if(dist[nx][ny] != -1 && dist[nx][ny] <= dist2[cur.first][cur.second]+1 || board[nx][ny] == '#' || dist2[nx][ny] >= 0)  continue;
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            q2.push({nx, ny});
        }
    }
//    for(int i=0; i<r; i++) {
//        for (int j = 0; j < c; j++) {
//            cout << dist2[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    cout << "IMPOSSIBLE";
    }


