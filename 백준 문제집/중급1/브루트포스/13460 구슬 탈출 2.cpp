#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[11][11];
pair<int, int> dest;
int dy[] = {-1, 0, 1, 0}; // 상, 좌, 하, 우
int dx[] = {0, -1, 0, 1};
//bool isFinish;
bool changeOrder;
int ans = 11;

// k번째에 dir방향으로 기울이기
void dfs(int k, pair<int, int> preRedB, pair<int, int> preBlueB, pair<int, int> redB, pair<int, int> blueB, int dir, bool isFinish) {

    if(isFinish) {
        return;
    }

    if(k == 10) {
        isFinish = true;
        return;
    }

    preRedB.first = redB.first;
    preRedB.second = redB.second;
    preBlueB.first = blueB.first;
    preBlueB.second = blueB.second;

    while(true) { // 빨간공 먼저 이동
        int ny = redB.first + dy[dir];
        int nx = redB.second + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) break;
        if(board[ny][nx] == '#')    break;
        if(ny == blueB.first && nx == blueB.second) { // 이동 중에 만나면 멈추고 파란공 이동
            changeOrder = true;
            break;
        }
        redB = make_pair(ny, nx);
        if(redB.first == dest.first && redB.second == dest.second) {
            isFinish = true;
        }
    }

    while(true) { // 파란공 이동
        int ny = blueB.first + dy[dir];
        int nx = blueB.second + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) break;
        if(board[ny][nx] == '#')    break; // 벽 만나면 멈추기
        if(ny == dest.first && nx == dest.second) {
            isFinish = false;
            return;
        }
        if(ny == redB.first && nx == redB.second)   break; // 빨간공 만나면 멈추기
        blueB = make_pair(ny, nx);
    }

    if(changeOrder) { // 빨간공 먼저 움직이므로 파란공 움직이고 더 움직일 수 있는지 확인후 이동
        while(true) {
            int ny = redB.first + dy[dir];
            int nx = redB.second + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) break;
            if(board[ny][nx] == '#')    break;
            if(ny == blueB.first && nx == blueB.second) break;
            redB = make_pair(ny, nx);
            if(redB.first == dest.first && redB.second == dest.second) {
                isFinish = true;
            }
        }
        changeOrder = false;
    }

    if(isFinish) {
        ans = min(ans, k+1);
        return;
    }

    if(redB.first == preRedB.first && redB.second == preRedB.second && blueB.first == preBlueB.first && blueB.second == preBlueB.second) {
        return;
    } // 빨간공, 파란공 모두 이동하지 않은 경우. prunning

    for(int d=0; d<4; d++) {
        if(((dir + d) % 2) == 0) continue; // 위로 기울인 후 바로 아래로 기울이는 경우 건너뛰기
        dfs(k+1, preBlueB, preRedB, redB, blueB, d, isFinish);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    pair<int, int> redB;
    pair<int, int> blueB;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'O') {
                dest = make_pair(i, j);
            }
            else if(board[i][j] == 'R') {
                redB = make_pair(i, j);
            } else if(board[i][j] == 'B') {
                blueB = make_pair(i, j);
            }
        }
    }

    // 1. 완전탐색으로 현재 구슬 상태에서 4방향을 모두 기울여서 모든 경우 탐색
    // 2. 빨간 구슬만 구멍으로 들어가는 경우 최소값 갱신
    // 3. 10번이 넘어가도 구멍으로 들어가지 않으면 -1 출력후 종료
    for(int dir=0; dir<4; dir++) {
        dfs(0, redB, blueB, redB, blueB, dir, false);
//        isFinish = false;
    }
    if(ans > 10) {
        cout << -1;
    } else {
        cout << ans;
    }
}