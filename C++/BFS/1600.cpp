#include <bits/stdc++.h>
using namespace std;

int board[201][201];
bool vis[201][201][31];
int dx1[] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy1[] = {2, 1, -2, -1, 2, 1, -2, -1};
int dx2[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, w, h;
    cin >> k >> w >> h;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, 0}}); // x좌표, y좌표, 이동 횟수, 점프 횟수
    vis[0][0][0] = true; // x좌표, y좌표, 점프 횟수
    while(!q.empty()) {
        int x, y, cnt, jump;
        x = q.front().first.first;
        y = q.front().first.second;
        cnt = q.front().second.first;
        jump = q.front().second.second;
        q.pop();
        if(x == h-1 && y == w-1) { // 도착점에 도달 시 이동 횟수 출력
            cout << cnt;
            return 0;
        }
        if(jump < k) { // 점프 횟수가 남았으면
            for(int dir=0; dir<8; dir++) {
                int nx = x + dx1[dir];
                int ny = y + dy1[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w)  continue;
                if(board[nx][ny] == 1 || vis[nx][ny][jump+1])  continue;
                q.push({{nx, ny}, {cnt+1, jump+1}}); // 점프한 곳을 push
                vis[nx][ny][jump+1] = true;
            }
        }
        for(int dir=0; dir<4; dir++) { // 점프가 아닐 경우
            int nx = x + dx2[dir];
            int ny = y + dy2[dir];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w)   continue;
            if(board[nx][ny] == 1 || vis[nx][ny][jump])  continue;
            q.push({{nx, ny}, {cnt+1, jump}});
            vis[nx][ny][jump] = true;
        }
        // 각 지점에서 점프와 점프가 아닌 경우를 모두 살핌
        // vis[nx][ny][jump]와 vis[nx][ny][jump+1]은 다르다.
        // vis[nx][ny][0]은 점프를 하지 않고 (nx, ny)에 도달하는 경우고,
        // vis[nx][ny][1]은 점프를 1번 하고 (nx, ny)에 도달하는 경우이다.
    }
    cout << -1; // 큐에 모든 원소가 없을 때 까지 도착점에 도달하지 못할 경우 출력
}


// 2206 벽 부수고 이동하기 문제와 유사. 부순 벽의 횟수를 저장해둠