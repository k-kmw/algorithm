#include <bits/stdc++.h>

using namespace std;

int w, h;
char board[100][100];
int vis[100][100];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1}; // 상 좌 하 우
int fy, fx;

bool checkRange(int y, int x) {
    if(y >= 0 && y < h && x >= 0 && x < w)  return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue< pair<pair<int, int>, pair<int, int> > > q; // 좌표, 방향, 개수
    cin >> w >> h;

    for(int i=0; i<h; i++) {
        fill(vis[i], vis[i]+w, INT_MAX);
    }

    bool isFirst = true;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'C' && isFirst) {
                for(int dir=0; dir<4; dir++) {
                    q.push(make_pair(make_pair(i, j), make_pair(dir, 0)));
                    vis[i][j] = 0;
                }
                isFirst = false;
            } else if (board[i][j] == 'C') {
                fy = i;
                fx = j;
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int y = cur.first.first;
        int x = cur.first.second;
        int dir = cur.second.first;
        int cnt = cur.second.second;

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
//            cout << ny << ' ' << nx << ' ' << cnt << ' ' << dir << '\n';
            int nCnt = cnt;
            if (!checkRange(ny, nx) || board[ny][nx] == '*') continue;
            if(dir != i) nCnt += 1;
            if(vis[ny][nx] >= nCnt) {
                vis[ny][nx] = nCnt;
                q.push(make_pair(make_pair(ny, nx), make_pair(i, nCnt)));
            }
        }
    }
    cout << vis[fy][fx];

    return 0;
}