#include <bits/stdc++.h>
using namespace std;
string board[5];
char arr[7];
bool isused[25];
bool vis[5][5];
int ans;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool moreFour;
bool adjacent;

void bfs() {
    for(auto & vi : vis)
        fill(vi, vi+5, 0);
    adjacent = false;
    queue<pair<int, int>> q;
    for(int i=0; i<25; i++) {
        if(isused[i]) {
            int x = i/5;
            int y = i % 5;
            q.push({x, y});
            vis[x][y] = true;
            break;
        }
    }
    int cnt=1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            int a = 5*nx + ny;
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5)  continue;
            if(vis[nx][ny] || !isused[a]) continue;
            q.push({nx, ny});
            vis[nx][ny] = true;
            cnt++;
        }
    }
//    cout << cnt << '\n';
    if(cnt == 7) {
//        cout << "ADj";
        adjacent = true;
    }
}

void func(int k, int st) {
    moreFour = false;
    if(k==7) {
        int cnt=0;
        for(char c : arr) {
            if(c == 'S')
                cnt++;
        }
        if(cnt >= 4) {
            moreFour = true;
            bfs();
        }

        if(moreFour) {
            if(adjacent) {
                ans++;
            }
        }
        return;
    }

    for(int i=st; i<25; i++) {
        arr[k] = board[i/5][i%5];
        isused[i] = true;
        func(k+1, i+1);
        isused[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(auto & i : board)
        cin >> i;
    func(0, 0);
    cout << ans;
}