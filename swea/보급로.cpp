#include<bits/stdc++.h>
using namespace std;

int n;
char board[101][101];
int d[101][101];
bool vis[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> board[i][j];
        for(int i=0; i<n; i++)
            fill(vis[i], vis[i]+n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(int dir=0; dir<4; dir++) {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n)  continue;
                if(!vis[ny][nx] || d[cur.first][cur.second] + board[ny][nx] - '0' < d[ny][nx]) {
                    vis[ny][nx] = true;
                    q.push({ny, nx});
                    d[ny][nx] = d[cur.first][cur.second] + board[ny][nx] - '0';
                }
            }
        }
        cout << '#' << test_case << ' ';
        cout << d[n-1][n-1] << '\n';
    }
    return 0;
}