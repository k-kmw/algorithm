#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
bool vis[55][55];
int main() {
    int r, c;

    cin >> r >> c;

    char board[r][c];
    queue<pair<int, int>> waters;
    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> board[i][j];
            if(board[i][j] == '*') {
                waters.push({i, j});
            } else if(board[i][j] == 'S') {
                q.push({{i, j}, 0});
                vis[i][j] = true;
            }
        }
    }

    int depth = 0;
    while(!q.empty()) {
        // 1. 물 이동
        while(!waters.empty()) {
            auto water = waters.front();
            waters.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ny = water.first + dy[dir];
                int nx = water.second + dx[dir];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (board[ny][nx] == 'D' || board[ny][nx] == 'X' || board[ny][nx] == '*' || board[ny][nx] == 'S') continue;
                board[ny][nx] = '*';
            }
        }

        // 2. 도치 이동

        while(true) {
            if(q.empty()) {
                break;
            }
            auto cur = q.front();
            if(cur.second != depth) {
                break;
            }
            q.pop();
//            cout << "cur: " << cur.first.first << ' ' << cur.first.second << '\n';
            for(int dir=0; dir<4; dir++) {
                int ny = cur.first.first + dy[dir];
                int nx = cur.first.second + dx[dir];
                if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if(board[ny][nx] == 'D') {
                    cout << cur.second + 1 << '\n';
                    exit(0);
                }
                if(board[ny][nx] == '*' || board[ny][nx] == 'X' || vis[ny][nx]) continue;
                vis[ny][nx] = true;
                q.push({{ny, nx}, cur.second + 1});
            }
        }
        depth++;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(board[i][j] == '*') {
                    waters.push({i, j});
                }
            }
        }
//        for(int i=0; i<r; i++) {
//            for(int j=0; j<c; j++) {
//                cout << board[i][j] << " ";
//            }
//            cout << '\n';
//        }
//        cout << '\n';
    }
    cout << "KAKTUS" << '\n';
}