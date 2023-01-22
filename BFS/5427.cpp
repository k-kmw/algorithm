#include <bits/stdc++.h>
using namespace std;

string board[1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        bool escape = false;
        int w, h;
        cin >> w >> h;
        for(int i=0; i<h; i++) {
            fill(dist1[i], dist1[i] + w, -1);
            fill(dist2[i], dist2[i] + w, -1);
        }

        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;
        for(int i=0; i<h; i++) {
            cin >> board[i];
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '*') {
                    dist1[i][j] = 0;
                    q1.push({i, j});
                }
                if(board[i][j] == '@') {
                    dist2[i][j] = 0;
                    q2.push({i, j});
                }
            }
        }
        while(!q1.empty()) {
            auto cur = q1.front();
            q1.pop();
            for(int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w)  continue;
                if(dist1[nx][ny] >= 0 || board[nx][ny] == '#')  continue;
                dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
                q1.push({nx, ny});
            }
        }

        while(!q2.empty() && !escape) {
            auto cur = q2.front();
            q2.pop();
            for(int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w)  {
                    cout << dist2[cur.first][cur.second] + 1 << '\n';
                    escape = true;
                    break;
                }
                if(dist2[nx][ny] >= 0 || board[nx][ny] == '#' || dist1[nx][ny] != -1 && dist2[cur.first][cur.second]+1 >= dist1[nx][ny])  continue;
                dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
                q2.push({nx, ny});
            }
        }
        if(!escape)
            cout << "IMPOSSIBLE" << '\n';

    }
}


