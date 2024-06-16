#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];
bool vis[1001][1001][11];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    queue< pair< pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
    vis[0][0][1] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        cout << cur.first.first << ' ' << cur.first.second << '\n';
        int brokenCnt = cur.second.first;
        int cnt = cur.second.second;
        if(cur.first.first == n-1 && cur.first.second == m-1) {
            cout << cnt;
            return 0;
        }
        for(int dir=0; dir<4; dir++) {
            int ny = cur.first.first + dy[dir];
            int nx = cur.first.second + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(board[ny][nx] == '1' && brokenCnt < k && !vis[ny][nx][brokenCnt+1]) {
                q.push((make_pair(make_pair(ny, nx), make_pair(brokenCnt+1, cnt+1))));
                vis[ny][nx][brokenCnt+1] = true;
            } else if(!vis[ny][nx][brokenCnt]) {
                q.push((make_pair(make_pair(ny, nx), make_pair(brokenCnt, cnt+1))));
                vis[ny][nx][brokenCnt] = true;
            }
        }
    }
    cout << -1;
}