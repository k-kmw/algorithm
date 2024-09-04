#include <bits/stdc++.h>
using namespace std;
int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[] = {-1, 1,-2, 2, -2, 2, -1, 1};
bool vis[301][301];
int l;
int sy, sx;
int fy, fx;
int ans = 300*300;

void dfs(int y, int x, int cnt) {

    if(y == fy && x == fx) {
        ans = min(ans, cnt);
        return;
    }

    for(int dir=0; dir<8; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= l || nx < 0 || nx >= l) continue;
        if(vis[ny][nx]) continue;
        vis[ny][nx] = true;
        dfs(ny, nx, cnt+1);
        vis[ny][nx] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> l;
        cin >> sy >> sx;
        cin >> fy >> fx;

        ans = 300*300;
        vis[sy][sx] = true;
        dfs(sy, sx, 0);
        vis[sy][sx] = false;

        cout << ans << '\n';
    }
}

// 2^450이라 안되나..?