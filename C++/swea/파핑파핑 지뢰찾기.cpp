#include<bits/stdc++.h>
using namespace std;

char board[301][301];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool vis[301][301];
int n;
int ans;

int main(int argc, char** argv)
{

    int T;
    cin>>T;
    int test_case;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> board[i][j];

        for(int i=0; i<n; i++)
            fill(vis[i], vis[i]+n, false);
        ans = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == '*' || vis[i][j]) continue;
                int cnt = 0;
                for(int dir=0; dir<8; dir++) {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= n)  continue;
                    if(board[ny][nx] == '*')    cnt++;
                }
                if(cnt != 0)    continue;
                ans++;
                q.push({i, j});
                vis[i][j] = true;
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    cnt = 0;
                    for(int dir=0; dir<8; dir++) {
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n)  continue;
                        if(board[ny][nx] == '*')    cnt++;
                    }
                    if(cnt == 0) {
                        // cout << cur.first << cur.second << '\n';
                        for(int dir=0; dir<8; dir++) {
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            if(ny < 0 || ny >= n || nx < 0 || nx >= n)  continue;
                            if(vis[ny][nx]) continue;
                            q.push({ny, nx});
                            vis[ny][nx] = true;
                        }
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(board[i][j] != '*' && !vis[i][j])    {
                    // cout << i << j << '\n';
                    ans++;
                }
        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}