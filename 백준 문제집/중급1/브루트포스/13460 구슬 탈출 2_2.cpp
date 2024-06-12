#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[11][11];
pair<int, int> dest;
pair<int, int> red, blue;

int ans = 11;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
bool vis[11][11][11][11]; // ry, rx, by, bx 방문 체크
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'O') {
                dest = make_pair(i, j);
            } else if(board[i][j] == 'R') {
                red = make_pair(i, j);
            } else if(board[i][j] == 'B') {
                blue = make_pair(i, j);
            }
        }
    }
    // 초기 빨강, 파랑 공 위치 큐에 넣기. ry, rx, by, bx
    // 4방향으로 기울인 결과를 큐에 넣기.
    // 기울이면서 종료조건을 만족하면 최소 횟수 갱신후 종료

    queue< pair< pair<pair<int, int>, pair<int, int> >, int > > q;
    q.push(make_pair(make_pair(make_pair(red.first, red.second), make_pair(blue.first, blue.second)), 0));
    vis[red.first][red.second][blue.first][blue.second] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int dir=0; dir<4; dir++) {
            int ry = cur.first.first.first;
            int rx = cur.first.first.second;
            int by = cur.first.second.first;
            int bx = cur.first.second.second;
            int cnt = cur.second;

            if(cnt > 10) {
                break;
            }

            bool orderReverse = false;

            // 빨간공 이동
            while(true) {
                int ny = ry + dy[dir];
                int nx = rx + dx[dir];
                if(board[ny][nx] == '#')    break;
                if(ny == by && nx == bx) {
                    orderReverse = true;
                    break;
                }
                ry = ny;
                rx = nx;
                if(ry == dest.first && rx == dest.second) {
                    break;
                }
            }

            // 파란공 이동
            while(true) {
                int ny = by + dy[dir];
                int nx = bx + dx[dir];
                if(board[ny][nx] == '#')    break;
                if(!(ny == dest.first && nx == dest.second) && (ny == ry && nx == rx)) { // 구멍이 아닌데 빨간공이 있다면 이동을 멈춤. 구멍이면 이동
                    break;
                }
                by = ny;
                bx = nx;
                if(by == dest.first && bx == dest.second)    break;
            }

            // 빨간공이 파란공에 막혀 이동이 못하는 경우 파란공을 이동시키고 한 번더 이동 시도
            if(orderReverse) {
                while(true) {
                    int ny = ry + dy[dir];
                    int nx = rx + dx[dir];
                    if(board[ny][nx] == '#')    break;
                    if(ny == by && nx == bx)    break;
                    ry = ny;
                    rx = nx;
                    if(ry == dest.first && rx == dest.second)   break;
                }
            }

//            cout << ry << ' ' << rx << '\n';
//            cout << by << ' ' << bx << '\n';
            if(by == dest.first && bx == dest.second) continue;
            if(ry == dest.first && rx == dest.second) {
                ans = min(ans, cnt+1);
            }
            if(vis[ry][rx][by][bx]) continue;
            vis[ry][rx][by][bx] = true;
            q.push(make_pair(make_pair(make_pair(ry, rx), make_pair(by, bx)), cnt+1));
        }
    }
    if(ans > 10) {
        cout << -1;
    } else {
        cout << ans;
    }
}