#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[25][25];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<pair<int, int>> coins;
int ans = INT_MAX;

bool isOut(int y, int x) {
    if(y < 0 || y >= n || x < 0 || x >= m)  return true;
    return false;
}

void dfs(int k, int y, int x, int yy, int xx) {
    if(k >= 11) {
        return;
    }

    for(int dir=0; dir<4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        int nyy = yy + dy[dir];
        int nxx = xx + dx[dir];

        if(isOut(ny, nx) && isOut(nyy, nxx)) {
            continue;
        }
        if(isOut(ny, nx) && !isOut(nyy, nxx)) {
            ans = min(ans, k);
            break;
        }
        if(!isOut(ny, nx) && isOut(nyy, nxx)) {
            ans = min(ans, k);
            break;
        }
        if(board[ny][nx] == '#') {
            ny = y;
            nx = x;
        }
        if(board[nyy][nxx] == '#') {
            nyy = yy;
            nxx = xx;
        }
        if(ny == y && nx == x && nyy == yy && nxx == xx) continue;
        dfs(k+1, ny, nx, nyy, nxx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'o') {
                coins.push_back({i, j});
            }
        }
    }
    dfs(1, coins[0].first, coins[0].second, coins[1].first, coins[1].second);
    if(ans == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}