#include <bits/stdc++.h>
using namespace std;

int n, m, p;
int s[10];
char board[1005][1005];
bool vis[1005][1005];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int cnt[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 큐1에 시작점을 넣기
    // 2. 큐1이 빌 때까지 큐2에 depth 0으로 넣기 => 큐1에서 같은 성의 번호를 가진 성의 좌표를 큐2에 넣기
    // 3. 큐2에서 depth가 si가 되거나 or 큐2가 빌때까지 bfs 탐색 수행
    // 4. depth == si인 것을 큐1에 다시 넣기
    // 3.4 => 큐2에서 depth가 s[i]가 될 때까지 확장하기. 마지막 depth일 떄 큐1에 넣기.
    // 마지막 depth가 다음 확장 가능한 후보이기 때문
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) {
        cin >> s[i];
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != '.' && board[i][j] != '#') {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    int turn = 1;
    queue<pair<pair<int, int>, int>> q2;
    while(!q.empty()) {

        int qsize = q.size();
        while(qsize--) { // 성 확장 가능한 지점 추가 (depth 0)
            auto cur = q.front();
            q.pop();
            int y = cur.first;
            int x = cur.second;
            if(board[y][x] - '0' == turn) { // turn과 일치하는 번호의 성을 확장
                q2.push({{y, x}, 0}); // depth 0으로 추가
                vis[y][x] = true;
            } else {
                q.push({y, x});
            }
        }

        while(!q2.empty()) { // 확장 가능한 지점에서 depth=sum[i]번 까지 확장하기. q2에는 하나의 번호의 성만 들어 있음
            auto cur = q2.front();
            q2.pop();
            int y = cur.first.first;
            int x = cur.first.second;
            int num = board[y][x] - '0';
            int depth = cur.second;

            for(int dir=0; dir<4; dir++) {
                int ny = y + dy[dir];
                int nx = x  + dx[dir];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(vis[ny][nx] || board[ny][nx] != '.') continue;

                if(depth+1 == s[num]) { // 마지막 depth에 추가한 곳이 다음 확장 가능한 지점의 후보
                    q.push({ny, nx});
                    vis[ny][nx] = true;
                    board[ny][nx] = board[y][x];
                } else { // s[i] depth까지 확장
                    q2.push({{ny, nx}, depth+1});
                    vis[ny][nx] = true;
                    board[ny][nx] = board[y][x];
                }
                // s[i]의 최대값이 10^9이지만, 확장 가능한 지점은 board의 크기인 10^6이 최대이고, 중복 방문을 하지 않고 빈칸만 방문하므로 더 작아짐
            }
        }

        turn = (turn % p) + 1; // 다음 성을 확장
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != '.' && board[i][j] != '#') {
                int num = board[i][j] - '0';
                cnt[num]++;
            }
        }
    }
    for (int i = 1; i <= p; i++) {
        cout << cnt[i] << ' ';
    }
}