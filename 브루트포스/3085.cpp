#include <bits/stdc++.h>
using namespace std;
string board[51];
bool vis[51][51];
int dx[] = {1, 0};
int dy[] = { 0, 1};
int n;
int ans;

void calculate() {
//    cout << "======================\n";
    for(int i=0; i<n; i++) {
        int tmp = 1;
        for(int j=0; j<n-1; j++){
            if(board[i][j] == board[i][j+1]) {
                tmp += 1;
            }
            else {
//                cout << board[i][j] << ' ' << tmp << ' ';
                ans = max(ans, tmp);
                tmp = 1;
            }
            ans = max(ans, tmp);
        }
//        cout << '\n';
    }
    for(int j=0; j<n; j++) {
        int tmp = 1;
        for(int i=0; i<n-1; i++){
            if(board[i][j] == board[i+1][j]) {
                tmp += 1;
            }
            else {
                ans = max(ans, tmp);
//                cout << board[i][j] << ' ' << tmp << ' ';
                tmp = 1;
            }
        }
//        cout << '\n';
        ans = max(ans, tmp);
    }
}

void solve(int y, int x) {
    for(int dir=0; dir<2; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >=n || ny >= n) continue;
        if(vis[ny][nx] || board[y][x] == board[ny][nx]) continue;
        char tmp = board[y][x];
        board[y][x] = board[ny][nx];
        board[ny][nx] = tmp;
        calculate();
        board[ny][nx] = board[y][x];
        board[y][x] = tmp;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)  cin >> board[i];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            solve(i, j);

    cout << ans;
}