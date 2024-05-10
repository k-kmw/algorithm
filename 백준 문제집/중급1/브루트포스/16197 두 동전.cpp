#include <bits/stdc++.h>

using namespace std;

int n, m;
char board[25][25];
vector<pair<int, int>> coins;
int ans;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
bool vis[2][25][25];
bool isOut[2];

// k번째 버튼을 dir방향으로 누른다.
void dfs(int k, int c, int o) {
    if (k == 11) {
        return;
    }
    if (ans != 0) {
        return;
    }
    if (c == 1) {
        int cnt = 0;
        for (auto coin: coins) {
            int y = coin.first;
            int x = coin.second;
            if (y < 0 || y >= n || x < 0 || x >= m) cnt++;
        }
        if (cnt == 1) {
            ans = k;
            return;
        }
    }

    for (int dir = 0; dir < 4; dir++) {
        int y = coins[c].first;
        int x = coins[c].second;
        cout << y << ' ' << x << '\n';
        y += dy[dir];
        x += dx[dir];
        if (c >= 0 && c < 2 && y >= 0 && y < n && x >= 0) {
            if(isOut[c]) {
                dfs(k, (c%2)+1, o);
            }
            if(vis[c][y][x]) continue;
            coins[c].first = y;
            coins[c].second = x;
            vis[c][y][x] = true;

            dfs(k+1, (c%2)+1, o);

            vis[c][y][x] = false;
            coins[c].first -= dy[dir];
            coins[c].second -= dx[dir];
        } else {
            isOut[c] = true;
            dfs(k+1, (c%2)+1, o+1);
            isOut[c] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 동전 2개를 이동 시킴 상/하/좌/우 (백트래킹)
    // 2. 하나의 동전만 떨어진 상태인지 확인
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'o') {
                coins.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        int y = coins[i].first;
        int x = coins[i].second;
        vis[i][y][x] = true;
    }
    dfs(0, 0, 0);
    cout << ans << '\n';
}