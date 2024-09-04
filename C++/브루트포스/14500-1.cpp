#include <bits/stdc++.h>
using namespace std;
int board[501][501];
bool visited[501][501];
int n, m;
int ans;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int tmp;

void dfs(int y, int x, int k) {
    if(k == 3) {
        ans = max(ans, tmp);
        return;
    }
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        visited[ny][nx] = true;
        tmp += board[ny][nx];
        dfs(ny, nx, k+1);
        tmp -= board[ny][nx]; // backtrack
        visited[ny][nx] = false; // backtrack
    }

    // ㅜ, ㅗ, ㅏ, ㅓ가 보드판을 벗어나지 않는 범위에서 계산
    if(y < n-1 && x < m-2) { // ㅜ
        ans = max(ans, board[y][x] + board[y][x+1] + board[y][x+2] + board[y+1][x+1]);
    }
    if(y < n-1 && x > 0 && x < m-1) { // ㅗ
        ans = max(ans, board[y][x] + board[y+1][x] + board[y+1][x-1] + board[y+1][x+1]);
    }
    if(y < n-2 && x < m-1) { // ㅏ
        ans = max(ans, board[y][x] + board[y+1][x] + board[y+2][x] + board[y+1][x+1]);
    }
    if(y < n-2 && x > 0) { // ㅓ
        ans = max(ans, board[y][x] + board[y+1][x] + board[y+1][x-1] + board[y+2][x]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = true;
            tmp += board[i][j];
            dfs(i, j, 0);
            tmp -= board[i][j]; // backtrack
            visited[i][j] = false; // backtrack
        }
    }
    cout << ans;
}