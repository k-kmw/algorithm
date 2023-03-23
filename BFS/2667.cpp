#include <bits/stdc++.h>
using namespace std;
string board[26];
bool vis[26][26];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int cnt;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> board[i];

    queue<pair<int, int>> q;
    vector<int> ans;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == '1' && !vis[i][j]) {
                cnt++;
                int house = 1;
                q.push({i, j});
                vis[i][j] = true;
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx >= n || nx < 0 || ny >= n || ny < 0)    continue;
                        if(board[nx][ny] == '0')    continue;
                        if(vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                        house++;
                    }
                }
                ans.push_back(house);
            }
        }
    }
    cout << cnt << '\n';
    sort(ans.begin(), ans.end());
    for(auto v : ans) {
        cout << v << '\n';
    }
}