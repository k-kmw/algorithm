#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[5];
bool vis[5][5];
int ans;
// (i,j)에서 한 조각의 직사각형을 완성?
// (i,j)에서 오른쪽으로 1, 2, 3, ..., m
// (i,j)에서 아래로 1, 2, 3, ..., n
void dfs(int y, int x) {

    if(y == n) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            int tmp = 0;
            for(int j=0; j<m; j++) {
                if(vis[i][j]) {
                    tmp = tmp*10 + board[i][j] - '0';
                } else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }

        for(int j=0; j<m; j++) {
            int tmp = 0;
            for(int i=0; i<n; i++) {
                if(!vis[i][j]) {
                    tmp = tmp*10 + board[i][j] - '0';
                } else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }
        ans = max(ans, sum);
        return;
    }

    if(x == m) {
        dfs(y+1, 0);
        return;
    }
    vis[y][x] = true;
    dfs(y, x+1);

    vis[y][x] = false;
    dfs(y, x+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> board[i];
    }
    dfs(0, 0);
    cout << ans << '\n';
}