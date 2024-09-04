#include<bits/stdc++.h>
using namespace std;

int board[16][16];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool vis[16][16];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> board[i][j];
            }
        }
        for(int i=0; i<16; i++)
            fill(vis[i], vis[i]+16, false);
        pair<int, int> st;
        cin >> st.first >> st.second;
        pair<int, int> en;
        cin >> en.first >> en.second;
        cout << '#' << test_case << ' ';
        queue<pair<pair<int, int>, int>> q;
        q.push({{st.first, st.second}, 0});
        vis[st.first][st.second] = true;
        bool finish = false;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(int dir=0; dir<4; dir++) {
                int ny = cur.first.first + dy[dir];
                int nx = cur.first.second + dx[dir];
                int t = cur.second;
                if(ny == en.first && nx == en.second) {
                    cout << t+1 << '\n';
                    finish = true;
                    break;
                }
                if(ny >= n || nx >= n || nx < 0 || ny < 0)  continue;
                if(vis[ny][nx]) continue;
                if(board[ny][nx] == 1)  continue;
                if(board[ny][nx] == 2) {
                    if(t % 3 != 2) {
                        q.push({{cur.first.first, cur.first.second}, t+1});
                    }
                    else {
                        q.push({{ny, nx}, t+1});
                        vis[ny][nx] = true;
                    }
                }
                if(board[ny][nx] == 0) {
                    q.push({{ny, nx}, t+1});
                    vis[ny][nx] = true;
                }
            }
            if(finish)  break;
        }

        if(!finish) {
            cout << -1 << '\n';
        }
    }
    return 0;
}