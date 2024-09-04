#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];
int dist[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    queue<pair<int, int>> q;
    bool escape = false;
    for(int i=0; i<n; i++)
        fill(dist[i], dist[i]+m, -1);
    dist[0][0] = 1;
    q.push({0, 0});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)  continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] == '1')   continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    int mn=1000005;
    if(dist[n-1][m-1] != -1) {
        escape = true;
        mn = dist[n-1][m-1];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == '1') {
                board[i][j] = '0';
                queue<pair<int, int>> q;
                for(int k=0; k<n; k++)
                    fill(dist[k], dist[k]+m, -1);
                dist[0][0] = 1;
                q.push({0, 0});
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m)  continue;
                        if(dist[nx][ny] >= 0 || board[nx][ny] == '1')   continue;
                        dist[nx][ny] = dist[cur.first][cur.second] + 1;
                        q.push({nx, ny});
                    }
                }
                board[i][j] = '1';
                if(dist[n-1][m-1] != -1) {
                    mn = min(mn, dist[n - 1][m - 1]);
                    escape = true;
                }
            }
        }
    }
    if(escape)
        cout << mn;
    else
        cout << -1;
}

// 시간 초과 풀이(완전 탐색). 시간 복잡도 O(N^2M^2)
// n과 m이 그렇게 크지 않아서 시간 복잡도를 계산해보지 않고 풀었는데 시간초과로 틀렸다.


