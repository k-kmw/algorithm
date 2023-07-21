#include <bits/stdc++.h>
using namespace std;
string board[51];
string copyBoard[51];
int mx;
int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void calculate(bool isSameRow, int a, int na) {
    cout << isSameRow << ' ' << a << ' ' << na <<'\n';
    if(isSameRow) {
        queue<char> q;
        q.push(board[0][a]);
        char cur = q.front();
        q.pop();
        while(!q.empty()) {
            int tmp = 0;
            for(int i=0; i<n; i++) {
                if(cur == board[i][a]) {
                    tmp++;
                }
                else if(q.back() != board[a][i]) {
                    q.push(board[i][a]);
                }
            }
            mx = max(mx, tmp);
        }
        q.push(board[0][na]);
        cur = q.front();
        q.pop();
        while(!q.empty()) {
            int tmp = 0;
            for(int i=0; i<n; i++) {
                if(cur == board[i][na]) {
                    tmp++;
                }
                else if(q.back() != board[a][i]) {
                    q.push(board[i][na]);
                }
            }
            mx = max(mx, tmp);
        }
    }
    else {
        queue<char> q;
        q.push(board[a][0]);
        char cur = q.front();
        q.pop();
        while(!q.empty()) {
            int tmp = 0;
            for(int i=0; i<n; i++) {
                if(cur == board[a][i]) {
                    tmp++;
                }
                else if(q.back() != board[a][i]) {
                    q.push(board[a][i]);
                }
            }
            mx = max(mx, tmp);
        }
        q.push(board[na][0]);
        cur = q.front();
        q.pop();
        while(!q.empty()) {
            int tmp = 0;
            for(int i=0; i<n; i++) {
                if(cur == board[na][i]) {
                    tmp++;
                }
                else if(q.back() != board[na][i]) {
                    q.push(board[na][i]);
                }
            }
            mx = max(mx, tmp);
        }
    }
}

void solve(int y, int x) {
    for(int dir=0; dir<4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(board[y][x] == board[ny][nx]) continue;
        bool isSameRow = false;
        if(ny == y) isSameRow = true;
        char tmp = board[y][x];
        board[y][x] = board[ny][nx];
        board[ny][nx] = tmp;
        if(isSameRow) calculate(isSameRow, x, nx);
        else calculate(isSameRow, y, ny);
        board[ny][nx] = board[y][x];
        board[y][x] = tmp;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)  cin >> board[i];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            solve(i, j);
        }
    }
    cout << mx;

}
// 처음 생각나는대로 풀다가 못풀었음... 쉽게 바꿔서 생각하자..!