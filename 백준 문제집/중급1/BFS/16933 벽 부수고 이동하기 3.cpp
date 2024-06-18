#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
bool vis[1005][1005][11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 벽은 낮에만 부술 수 있다.
    // (ny, nx)가 빈칸일 경우 이동, 머무르기 두 가지 모두 고려
    // (ny, nx)가 벽일 경우 벽 부수고 이동, 머무르기 두 가지 모두 고려
    // 벽일 경우 벽 부수기 전 낮인지 확인하고 부술 수 있는 횟수 확인하기
    // 한 번 이동할 때마다 낮과 밤이 바뀜

    int n, m, k;
    cin >> n >> m >> k;
    char board[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<pair<pair<int, int>, pair<int, bool>>, int>> q; // 좌표, 벽 부순 횟수, 낮/밤 여부
    q.push({{{0, 0}, {0, true}}, 1});
    vis[0][0][0] = true;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int y = cur.first.first.first;
        int x = cur.first.first.second;
        int brokenCnt = cur.first.second.first;
        bool isDay = cur.first.second.second;
        int cnt = cur.second;

//        cout << y << ' ' << x << ' ' << brokenCnt << '\n';

        if(y == n-1 && x == m-1) {
            cout << cnt;
            return 0;
        }

        for(int dir=0; dir<4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(vis[ny][nx][brokenCnt]) continue;

            // 벽인 경우
            if(board[ny][nx] == '1') {
                if(brokenCnt+1 <= k && isDay && !vis[ny][nx][brokenCnt+1]) {
                    q.push({{{ny, nx}, {brokenCnt+1, false}}, cnt+1});
                    vis[ny][nx][brokenCnt+1] = true;
                } else if(brokenCnt+1 <= k && !isDay && !vis[ny][nx][brokenCnt+1]) {
                    q.push({{{y, x}, {brokenCnt, true}}, cnt+1});

                }
            } else {
                q.push({{{ny, nx}, {brokenCnt, !isDay}}, cnt+1});
                vis[ny][nx][brokenCnt] = true;
            }
        }
    }
    cout << -1;
}