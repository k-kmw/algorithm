#include <bits/stdc++.h>
using namespace std;

/*
 * 이 문제 풀면서 엄청 헤맸다.
 * 방향을 고려하지 않고 거울의 최소 개수를 갱신하니까 시간과 메모리 초과가 발생함. (방문했던 좌표를 계속 방문하므로.. 하지만 재방문 하지 않으면 최소값을 보장할 수 없음.)
 * 그래서 특정 방향으로 해당 좌표에 들어온 경우 기존 해당 좌표의 해당 방향의 거울의 개수와 비교해서, 개수가 더 작을 경우만 큐에 추가 해주었음. (즉, 새로운 경로가 최적 후보가 됨)
 * BFS 풀이.
 * 정해는 아닌 것 같지만, 실전에서 생각해볼만 한 것 같다.
 */

int w, h;
char board[100][100];
int mirrorCnt[100][100][4];
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
    queue<pair<pair<int, int>, pair<int, int> > > q; // 좌표, 거울 개수, 방향
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'C' && isFirst) {
                for(int dir=0; dir<4; dir++) {
                    q.push(make_pair(make_pair(i, j), make_pair(0, dir)));
                    isFirst = false;
                }
            } else if(board[i][j] == 'C') {
                fy = i;
                fx = j;
            }

            for(int k=0; k<4; k++) {
                mirrorCnt[i][j][k] = INT_MAX;
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int y = cur.first.first;
        int x = cur.first.second;
        int cnt = cur.second.first;
        int dir = cur.second.second;

        if(y == fy && x == fx) continue;

//        cout << y << ' ' << x << ' ' << cnt << ' ' << dir << '\n';

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nCnt = cnt;
            if(!checkRange(ny, nx) || board[ny][nx] == '*') continue;
            if(dir != i) nCnt += 1;
            if(mirrorCnt[ny][nx][i] <= nCnt) continue;
            mirrorCnt[ny][nx][i] = nCnt;
            q.push(make_pair(make_pair(ny, nx), make_pair(nCnt, i)));
        }
    }

    int mn = INT_MAX;
    for(int i=0; i<4; i++) {
        mn = min(mn, mirrorCnt[fy][fx][i]);
    }
    cout << mn;
    return 0;
}