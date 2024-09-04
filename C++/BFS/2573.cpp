#include <bits/stdc++.h>
using namespace std;

int board[300][300];
int height[300][300];
bool vis[300][300];
bool vis2[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int year, cnt;
bool meltAll = false;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            height[i][j] = board[i][j];
        }
    }

    while(true) {
        meltAll = true;
        year++;

        // 빙산 녹이는 부분
        for(int i=1; i<n-1; i++) { // 모든 빙산의 위치를 찾기 위해 이중 for문, 만약 시작위치를 하나로 고정하면 그 지점에서 상하좌우 모두 바다이면 진행이 멈춤
            for(int j=1; j<m-1; j++) {
                if(vis[i][j] || board[i][j] == 0)   continue; // 방문한 빙산 or 빙산이 아니면
                queue<pair<int, int>> q;
                q.push({i, j}); // (i, j)에서 bfs 시작
                vis[i][j] = true;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) { // 빙산의 상하좌우를 보고 바다이면 높이를 감소 시킴
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (board[nx][ny] != 0 && vis[nx][ny]) continue;
                        if (board[nx][ny] == 0) { // (nx, ny)가 바다 일 때
                            if (height[cur.first][cur.second] > 0) // height가 0보다 크면 현재 지점의 높이 감소
                                height[cur.first][cur.second]--;
                            continue; // (nx, ny)가 바다 일 때는 녹일 빙산이 없기 때문에 큐에 추가하지 않음
                        }
                        vis[nx][ny] = true; // (nx, ny)가 빙산의 다른 지점 일 때 큐에 추가
                        q.push({nx, ny});
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                board[i][j] = height[i][j]; // board를 최신 높이로 갱신
                vis[i][j] = false; // vis초기화
                vis2[i][j] = false; // vis2 초기화
                if (board[i][j] != 0) { // 빙산이 모두 다 안녹았는지 확인, 기본 true로 설정
                    meltAll = false;
                }
            }
        if(meltAll) { // 빙산이 모두 녹으면
            cout << 0;
            return 0;
        }
//        for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) {
//                cout << board[i][j] << ' ';
//            }
//            cout << '\n';
//        }
        //빙산이 나누어 졌는지 검사하는 부분
        cnt = 0;
        for (int i = 1; i < n - 1; i++) { // bfs를 돌며 분리된 빙산의 개수 세기
            for (int j = 1; j < m - 1; j++) {
                if (vis2[i][j] || board[i][j] == 0) continue;
//                cout << i << ' ' << j << '\n';
                queue<pair<int, int>> q2;
                cnt++; // 개수 증가
                q2.push({i, j});
                vis2[i][j] = true;
                while (!q2.empty()) {
                    auto cur = q2.front();
                    q2.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n - 1 || ny < 0 || ny >= m - 1) continue;
                        if (vis2[nx][ny] || board[nx][ny] == 0) continue;
                        vis2[nx][ny] = true;
                        q2.push({nx, ny});
                    }
                }
                if (cnt > 1) { // cnt가 1보다 크면 빙산이 분리 된 것이므로 출력
                    cout << year;
                    return 0;
                }
            }
        }
    }

}

// 시간 복잡도?



