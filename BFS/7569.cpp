#include <bits/stdc++.h>
using namespace std;

int board[101][101][101];
int dist[101][101][101];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int m, n, h;
    cin >> m >> n >> h;
    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            fill(dist[i][j], dist[i][j]+m, -1);

    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                cin >> board[i][j][k];
                if(board[i][j][k] == 1) { // 익은 토마토이면
                    dist[i][j][k] = 0; // 거리(시간) 0 설정
                    q.push({{i, j}, k}); // 큐에 추가
                }
            }
        }
    }

//    for(int i=0; i<h; i++) {
//        for(int j=0; j<n; j++) {
//            for(int k=0; k<m; k++) {
//                cout << board[i][j][k];
//            }
//            cout << '\n';
//        }
//    }


    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<6; dir++) {
            int nz = cur.first.first + dz[dir];
            int ny = cur.first.second + dy[dir];
            int nx = cur.second + dx[dir];
            if(nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(dist[nz][ny][nx] >= 0 || board[nz][ny][nx] != 0) continue;
            board[nz][ny][nx] = 1; // 익은 걸로 바꿔줌
            dist[nz][ny][nx] = dist[cur.first.first][cur.first.second][cur.second] + 1; // 거리(시간) 표시
            q.push({{nz, ny}, nx}); // 해당 지점을 큐에 넣음.
        }
    }

//    for(int i=0; i<h; i++) {
//        for(int j=0; j<n; j++) {
//            for(int k=0; k<m; k++) {
//                cout << dist[i][j][k];
//            }
//            cout << '\n';
//        }
//    }
    int mx = 0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(board[i][j][k] == 0) { // 안익은 토마토가 있으면 -1출력 후 종료
                    cout << -1;
                    return 0;
                }
                mx = max(mx, dist[i][j][k]); // 거리(시간) 최대값 구함
            }
        }
    }
    cout << mx;

}


