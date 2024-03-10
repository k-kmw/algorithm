#include <bits/stdc++.h>
using namespace std;
int w, h;
int board[53][53];
bool vis[53][53];
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int i, int j) {
    queue< pair<int, int> > q;
    q.push(make_pair(i, j));
    vis[i][j] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<8; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(board[ny][nx] == 0 || vis[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push(make_pair(ny, nx));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> w >> h;
        int cnt = 0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> board[i][j];
                vis[i][j] = false;
            }
        }

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(vis[i][j] || board[i][j] == 0) continue;
                cnt++;
                bfs(i, j);
            }
        }
        if(w != 0 && h != 0)
            cout << cnt << '\n';
        else {
            break;
        }
    }
}