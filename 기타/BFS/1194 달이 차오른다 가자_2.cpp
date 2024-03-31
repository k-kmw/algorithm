#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[55][55];
bool vis[55][55][64]; // 좌표, 키 유무 비트 마스킹
int dy[]= {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int main() {

    queue<pair< pair<int, int>, pair<int, int> > > q; // 좌표(i, j), key, 거리
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == '0') {
                q.push(make_pair(make_pair(i, j), make_pair(0, 0)));
                vis[i][j][0] = true;
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int y = cur.first.first;
        int x = cur.first.second;
        int keys = cur.second.first;
        int dist = cur.second.second;

        for(int dir=0; dir<4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(board[ny][nx] == '1') {
                cout << dist+1 << '\n';
                return 0;
            }
            if(vis[ny][nx][keys] || board[ny][nx] == '#') continue;
            if (board[ny][nx] >= 'a' && board[ny][nx] <= 'f') { // key를 만났을 경우
                vis[ny][nx][keys] = true;
                int newKeys = keys;
                newKeys |= (1 << board[ny][nx] - 'a');
                q.push(make_pair(make_pair(ny, nx), make_pair(newKeys, dist + 1)));
                continue;
            }
            if(board[ny][nx] >= 'A' && board[ny][nx] <= 'F') { // 벽을 만났을 경우
                if(keys & (1 << board[ny][nx] - 'A')) { // 해당되는 key가 있을 경우
                    vis[ny][nx][keys] = true;
                    q.push(make_pair(make_pair(ny, nx), make_pair(keys, dist+1)));
                }
                continue;
            }
            q.push(make_pair(make_pair(ny, nx), make_pair(keys, dist+1)));
            vis[ny][nx][keys] = true;
        }
    }
    cout << -1 << '\n';
}