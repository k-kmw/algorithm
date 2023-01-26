#include <bits/stdc++.h>
using namespace std;

int board[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    cin >> m >> n >> k;
    int pos[k][4];
    for(int i=0; i<k; i++)
        for(int j=0; j<4; j++)
            cin >> pos[i][j];

    for(int i=0; i<k; i++) {
        int sx = pos[i][0];
        int sy = pos[i][1];
        int fx = pos[i][2];
        int fy = pos[i][3];
        for(int b = sy; b<fy; b++) {
            for(int a = sx; a<fx; a++) {
                board[b][a] = 1;
            }
        }
    }

//    for(int i=0; i<m; i++) {
//        for(int j=0; j<n; j++)
//            cout << board[i][j] << ' ';
//        cout << '\n';
//    }

    int cnt = 0;
    vector<int> v;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            queue<pair<int, int>> q;
            if(vis[i][j] || board[i][j] == 1)   continue;
//            cout << i << " " << j << '\n';
            cnt++;
            vis[i][j] = true;
            q.push({i, j});
            int area = 0;
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                area++;
                for(int dir=0; dir<4; dir++) {
                    int ny = cur.first + dy[dir]; // cur.first가 y좌표
                    int nx = cur.second + dx[dir];
                    if(ny < 0 || ny >= m || nx < 0 || nx >= n)  continue;
                    if(vis[ny][nx] || board[ny][nx] == 1)   continue;
                    vis[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
            v.push_back(area);
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for(auto it: v) {
        cout << it << ' ';
    }
}




