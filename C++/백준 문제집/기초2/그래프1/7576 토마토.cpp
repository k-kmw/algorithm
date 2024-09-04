#include <bits/stdc++.h>
using namespace std;

int m, n;
int minDay;
int board[1001][1001];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    queue< pair<pair<int, int>, int> > q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                q.push(make_pair(make_pair(i, j), 0));
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        minDay = max(minDay, cur.second);
        for(int dir=0; dir<4; dir++) {
            int ny = cur.first.first + dy[dir];
            int nx = cur.first.second + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(board[ny][nx] != 0) continue;
            board[ny][nx] = 1;
            q.push(make_pair(make_pair(ny, nx), cur.second+1));
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 0) {
                minDay = -1;
                break;
            }
        }
        if(minDay == -1) {
            break;
        }
    }
    cout << minDay << '\n';
}