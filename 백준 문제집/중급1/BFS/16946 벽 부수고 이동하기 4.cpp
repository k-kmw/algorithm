#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1001][1001];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
map<int, int> land;

void bfs(int i, int j, int num) {
    queue< pair<int, int> > q;
    q.push(make_pair(i, j));
    board[i][j] = num;
    int cnt = 1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
//        cout << cur.first << cur.second << '\n';
        for(int dir=0; dir<4; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(board[ny][nx] != 0) continue;
            board[ny][nx] = num;
            q.push(make_pair(ny, nx));
            cnt++;
        }
    }
    land[num] = cnt; // 섬을 이루는 0의 개수 저장
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 하나의 0과 인접한 0을 하나의 섬으로 보고 번호를 매김
    // 각 섬에서 map[섬의 번호] = 섬을 구성하는 0의 개수로 저장

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }

    // 섬 번호 매기고, 각 섬을 이루는 0의 개수 세기
    int num = 2;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 0) {
                bfs(i, j, num++);
            }
        }
    }

    // 1의 상하좌우 확인하여, 4방향의 인접한 섬의 크기를 모두 더해줌
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 1) {
                int cnt = 1;
                bool vis[num];
                fill(vis, vis+num, false);
                for(int dir=0; dir<4; dir++) {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    int num2 = board[ny][nx];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    if(vis[num2]) continue; // 이미 방문한 섬(연결된 섬을 다시 방문하는 경우) 확인
                    cnt += land[num2];
                    vis[num2] = true;
                }
                cout << cnt%10;
            } else {
                cout << 0;
            }
        }
        cout << '\n';
    }
}