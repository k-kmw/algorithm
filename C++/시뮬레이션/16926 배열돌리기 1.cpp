#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int board[301][301];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void rotate() {

    for(int depth=0; depth < min(n, m)/2; depth++) {
        int y = depth;
        int x = depth;
        int start = board[y][x];
        int dir = 0;
        while (dir < 4) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < depth || ny >= n - depth || nx < depth || nx >= m - depth) {
                dir++;
                continue;
            }
            board[y][x] = board[ny][nx];
            y = ny;
            x = nx;
        }
        board[y + 1][x] = start;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    while(r--) {
        rotate();
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout <<  board[i][j] << ' ';
        }
        cout << '\n';
    }
}

