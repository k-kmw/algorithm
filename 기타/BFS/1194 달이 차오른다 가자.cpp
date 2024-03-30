#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[55][55];
bool vis[55][55][5000]; // 좌표, 키 개수
int dy[]= {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int main() {

    queue<pair< pair<int, int>, pair<set<char>, int> > > q;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == '0') {
                set<char> keys;
                q.push(make_pair(make_pair(i, j), make_pair(keys, 0)));
                vis[i][j][0] = true;
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int y = cur.first.first;
        int x = cur.first.second;
        set<char> keys = cur.second.first;
        int dist = cur.second.second;
        int keyHash = 0;
        for(char key : keys) {
            keyHash += key;
        }

//        cout << y << ' ' << x << ' ' << dist << '\n';
//        for(auto key : keys) {
//            cout << key << ' ';
//        }
//        cout << '\n';
        for(int dir=0; dir<4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(board[ny][nx] == '1') {
                cout << dist+1 << '\n';
                return 0;
            }
            if(vis[ny][nx][keyHash] || board[ny][nx] == '#') continue;
            if (board[ny][nx] >= 'a' && board[ny][nx] <= 'f') { // key를 만났을 경우
                vis[ny][nx][keyHash] = true;
                set<char> newKeys(keys);
                newKeys.insert(board[ny][nx]);
                q.push(make_pair(make_pair(ny, nx), make_pair(newKeys, dist + 1)));
                continue;
            }
            if(board[ny][nx] >= 'A' && board[ny][nx] <= 'F') { // 벽을 만났을 경우
                if(keys.find(board[ny][nx] + ('a' - 'A')) != keys.end()) { // 해당되는 key가 있을 경우
                    vis[ny][nx][keyHash] = true;
                    q.push(make_pair(make_pair(ny, nx), make_pair(keys, dist+1)));
                }
                continue;
            }
//            cout << "TEST" << '\n';
            q.push(make_pair(make_pair(ny, nx), make_pair(keys, dist+1)));
            vis[ny][nx][keyHash] = true;
        }
    }
    cout << -1 << '\n';
}