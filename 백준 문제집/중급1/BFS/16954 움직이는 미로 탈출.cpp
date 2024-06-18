#include <bits/stdc++.h>
using namespace std;

char board[10][10];
bool vis[10][10][100];
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool isFinish;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    deque< pair<int, int> > walls;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cin >> board[i][j];
//            if(board[i][j] == '#') {
//                walls.push_back(make_pair(i, j));
//            }
        }
    }

    // 출발지: (7, 0), 도착지: (0, 7)
    // 캐릭터 이동 -> 벽 이동. 벽이 캐릭터가 있는 칸으로 가면 캐릭터는 더 이상 움직일 수 없음.
    // 대각선 이동 가능, 현재 위치에 서있기 가능
    // 현재 위치에서 8방향 이동, 현재 위치에 서있기 모두 고려.
    // 방문 체크? 좌표 + 시간
    queue< pair<int, int> > q;
    q.push(make_pair(7, 0));
    vis[7][0][0] = true;

    int t = 0;
    while(!q.empty()) {

        // 사람 이동
        int qsize = q.size();
        while(qsize--) {
            auto cur = q.front();
            q.pop();
            int y = cur.first;
            int x = cur.second;

            // 목적지 정상 도착
            if(y == 0) {
                cout << 1;
                return 0;
            }

            // 벽이 이동해서 캐릭터가 있는 칸과 동일해 졌을 경우
            if(board[y][x] == '#') continue;

            // 현재 위치에서 기다리는 경우
            if(!vis[y][x][t+1]) {
                q.push(make_pair(y, x));
                vis[y][x][t+1] = true;
            }

            // 8방향 이동
            for(int dir=0; dir<8; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(ny < 0 || ny >= 8 || nx < 0 || nx >= 8) continue;
                if(board[ny][nx] == '#' || vis[ny][nx][t+1]) continue;
                q.push(make_pair(ny, nx));
                vis[ny][nx][t+1] = true;
            }
        }

        // 벽 이동 (벽이 위아래로 이웃한 경우, 아래 위치한 벽이 먼저 움직여야 함)
//        int wallSize = walls.size();
//        while(wallSize--) {
//            auto wall = walls.back();
//            walls.pop_back();
//            int y = wall.first;
//            int x = wall.second;
////            cout << y << ' ' << x << '\n';
//            if(y+1 >= 8) {
//                board[y][x] = '.';
//                continue;
//            }
//            board[y+1][x] = '#';
//            board[y][x] = '.';
//            walls.push_front(make_pair(y+1, x));
//        }
//        cout << '\n';
        for(int i=7; i>=1; i--) {
            for(int j=0; j<8; j++) {
                board[i][j] = board[i-1][j];
            }
        }
        for(int j=0; j<8; j++) {
            board[0][j] = '.';
        }
        t++;
    }
    cout << 0;
}