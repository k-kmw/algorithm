#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[51];
bool vis[51][51];
int sy, sx;
bool isCycle;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void dfs(int y, int x, char color, int cnt) {

//    cout << y << ' ' << x << '\n';

    if(isCycle) {
        return;
    }

    for(int dir=0; dir<4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] != color) continue;
        if(vis[ny][nx]) {
            if(ny == sy && nx == sx && cnt >= 4) {
                isCycle = true;
                return;
            } else {
                continue;
            }
        }
        vis[ny][nx] = true;
        dfs(ny, nx, color, cnt+1);
        vis[ny][nx] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> board[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            sy = i;
            sx = j;
//            cout << board[sy][sx] << '\n';
            vis[sy][sx] = true;
            dfs(i, j, board[i][j], 1);
            if(isCycle) {
                break;
            }
        }
        if(isCycle) {
            break;
        }
    }

    if(isCycle) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}