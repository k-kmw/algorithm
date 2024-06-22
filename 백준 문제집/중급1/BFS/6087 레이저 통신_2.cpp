#include <bits/stdc++.h>
using namespace std;

/**
 * 다익스트라 풀이
 * 다익스트라 코드가 기억이 잘 안나서 푸는데 헷갈렸음.
 */

int w, h;
char board[100][100];
bool vis[100][100][4];
int mirrorCnt[100][100];
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

    cin >> w >> h;
    bool isFirst = true;
    priority_queue<pair<pair<int, int>, pair<int, int> > > pq; // 거울 개수, 방향, 좌표
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'C' && isFirst) {
                for(int dir=0; dir<4; dir++) {
                    pq.push(make_pair(make_pair(0, dir), make_pair(i, j)));
                    vis[i][j][dir] = true;
                    isFirst = false;
                }
            } else if(board[i][j] == 'C') {
                fy = i;
                fx = j;
            }
            mirrorCnt[i][j] = INT_MAX;
        }
    }

    while(!pq.empty()) {
        auto cur = pq.top(); // 거울의 개수가 가장 작은 것 먼저 뽑기
        pq.pop();
        int cnt = -cur.first.first;
        int dir = cur.first.second;
        int y = cur.second.first;
        int x = cur.second.second;

        if(vis[y][x][dir]) continue; // 해당 좌표에 해당 방향으로 방문한 적이 있는지 확인. 이미 방문 했다면 continue

        vis[y][x][dir] = true;

//        cout << y << ' ' << x << ' ' << cnt << ' ' << dir << '\n';

        for(int i=0; i<4; i++) { // 최소 거울의 개수인 지점에서, 연결된 지점의 거울 개수 최소값 갱신
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nCnt = cnt;
            if(!checkRange(ny, nx) || board[ny][nx] == '*') continue;
            if(dir != i) nCnt += 1;
            if(mirrorCnt[ny][nx] >= nCnt) {
                mirrorCnt[ny][nx] = nCnt;
                pq.push(make_pair(make_pair(-nCnt, i), make_pair(ny, nx)));
            }
        }
    }

    cout << mirrorCnt[fy][fx];
    return 0;
}