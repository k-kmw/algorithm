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
    q.push({{0, 0}, {0, 0}});
    vis[0][0][0] = true;
    while(!q.empty()) {
        int x, y, cnt, jump;
        x = q.front().first.first;
        y = q.front().first.second;
        cnt = q.front().second.first;
        jump = q.front().second.second;
        q.pop();
        if(x == h-1 && y == w-1) {
            cout << cnt;
            return 0;
        }
        for(int dir=0; dir<4; dir++) {
            int nx = x + dx2[dir];
            int ny = y + dy2[dir];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w)   continue;
            if(board[nx][ny] == 1 || vis[nx][ny][jump])  continue;
            q.push({{nx, ny}, {cnt+1, jump}});
            vis[nx][ny][jump] = true;
        }
        if(jump < k) {
            for(int dir=0; dir<8; dir++) {
                int nx = x + dx1[dir];
                int ny = y + dy1[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w)  continue;
                if(board[nx][ny] == 1 || vis[nx][ny][jump+1])  continue;
                q.push({{nx, ny}, {cnt+1, jump+1}});
                vis[nx][ny][jump+1] = true;
            }
        }

    }
    cout << -1;
}


