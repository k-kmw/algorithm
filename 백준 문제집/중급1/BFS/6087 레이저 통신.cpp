#include <bits/stdc++.h>

using namespace std;

int w, h;
char board[101][101];
bool vis[101][101][101][3];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1}; // 상 좌 하 우
int fy, fx;
int ans = INT_MAX;

queue<pair<pair<pair<int, int>, pair<int, int> >, int> > q; // 좌표, 해당 칸의 종류(빈칸, '/', '\'), 누적 거울의 개수, 진행 방향
void moveRazor(int sty, int stx, int y, int x, int dir, int mirrorCnt) {

    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (ny < 0 || ny >= h || nx < 0 || nx >= w) return;
    if(board[ny][nx] == '*') return;
    if (ny == sty && ny == stx) return; // 시작점으로 가는 경우
    if (ny == fy && nx == fx) {
        ans = min(ans, mirrorCnt);
        return;
    }

    // 거울을 설치하지 않는 경우
    if (!vis[ny][nx][mirrorCnt][0]) {
        q.push(make_pair(make_pair(make_pair(ny, nx), make_pair(0, mirrorCnt)), dir));
        vis[ny][nx][mirrorCnt][0] = true;
    }

    // '/' 거울을 설치하는 경우
    if (!vis[ny][nx][mirrorCnt + 1][1]) {
        q.push(make_pair(make_pair(make_pair(ny, nx), make_pair(1, mirrorCnt + 1)), dir));
        vis[ny][nx][mirrorCnt + 1][1] = true;
    }

    // '\' 거울을 설치하는 경우
    if (!vis[ny][nx][mirrorCnt + 1][2]) {
        q.push(make_pair(make_pair(make_pair(ny, nx), make_pair(2, mirrorCnt + 1)), dir));
        vis[ny][nx][mirrorCnt + 1][2] = true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool isFirstC = true;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'C' && isFirstC) {
                for(int dir=0; dir<4; dir++) {
                    q.push(make_pair(make_pair(make_pair(i, j), make_pair(0, 0)), 0));
                }
                isFirstC = false;
            } else if (board[i][j] == 'C') {
                fy = i;
                fx = j;
            }
        }
    }
    // 하나의 C에서 BFS 탐색
    // 회전하지 않고 이동과 거울을 만나 시계로 회전, 반시계로 회전을 모두 고려하여 큐에 넣음
    // vis[101][101][101][3]: 누적 거울의 개수, 현재 칸의 거울 종류를 고려하여 방문 체크

    auto st = q.front();
    int sty = st.first.first.first;
    int stx = st.first.first.second;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int y = cur.first.first.first;
        int x = cur.first.first.second;
        int mirrorType = cur.first.second.first;
        int mirrorCnt = cur.first.second.second;
        int dir = cur.second;

        cout << y << ' ' << x << ' ' << mirrorType << ' ' << mirrorCnt << ' ' << dir << '\n';

        if (mirrorType == 0) { // 현재 칸이 거울이 없는 칸인 경우
            moveRazor(sty, stx, y, x, dir, mirrorCnt);
        } else if (mirrorType == 1) { // 현재 칸이 '/' 거울인 경우
            if (dir % 2 != 0) { // 상/하로 이동하는 경우
                dir = ((dir + 4) - 1) % 4;
            } else { // 좌우로 이동하는 경우
                dir = (dir + 1) % 4;
            }
            moveRazor(sty, stx, y, x, dir, mirrorCnt);
        } else if (mirrorType == 2) { // 현재 칸이 '\' 거울인 경우
            if (dir % 2 != 0) { // 상/하로 이동하는 경우
                dir = (dir + 1) % 4;
            } else { // 좌우로 이동하는 경우
                dir = ((dir + 4) - 1) % 4;
            }
            moveRazor(sty, stx, y, x,  dir, mirrorCnt);
        }
    }
    cout << ans;
}