#include <bits/stdc++.h>
using namespace std;

int n;
char board[11][11];
bool vis[11][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> area_vec;
int cnt;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!vis[i][j] && board[i][j] == 1) {
                q.push({i, j});
                vis[i][j] = true;
                cnt++;
            }
            int area = 0;
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n)  continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] == 0)  continue;
                    area++;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
                area_vec.push_back(area);
            }
        }
    }
    sort(area_vec.begin(), area_vec.end());
    cout << cnt << '\n';
    for(auto & a : area_vec) {
        cout << a << ' ';
    }
    return 0;
}