#include <bits/stdc++.h>
using namespace std;

int n, k;
int board[2005][2005];
int num = 1;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
bool vis[2005][2005];
int cnt;
int p[100005];

void make_set() {
    for(int i=1; i<=k; i++) {
        p[i] = i;
    }
}

int find(int a) {
    if(a == p[a])   return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if(rootA == rootB)  return;
//    cout << "union: " << a << ' ' << b << '\n';
    p[rootA] = rootB;
    cnt++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    // 1. board에 문명 발상지 표시 / 문명 발상지 큐에 넣기
    // 2. bfs로 문명 전파
    // 3. 이동하는 곳에 다른 문명이 있으면, 문명 번호를 기준으로 합치기 (union)
    // 4. 모든 문명이 결합되었는지 확인 - union할 때마다 cnt를 증가시켜서 k와 같은지 비교
    // 5. 모든 문명이 결합되지 않았으면 3번부터 반복
    queue<pair<int, int>> q;
    for(int i=0; i<k; i++) {
        int x, y;
        cin >> y >> x;
        board[y][x] = num++;
        q.push({y, x});
        vis[y][x] = true;
    }

    make_set();

    int year = 0;
    while(true) {
        queue<pair<int, int>> q2;
        year++;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
//            cout << cur.first << ' ' << cur.second << ' ' << board[cur.first][cur.second] << '\n';
            for(int dir=0; dir<4; dir++) {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if(ny < 1 || ny > n || nx < 1 || nx > n) continue;
                if(vis[ny][nx]) continue;
                board[ny][nx] = board[cur.first][cur.second];
                for(int d=0; d<4; d++) {
                    int nny = ny + dy[d];
                    int nnx = nx + dx[d];
                    if(nny < 1 || nny > n || nnx < 1 || nnx > n) continue;
                    if(board[nny][nnx] == board[ny][nx] || board[nny][nnx] == 0) continue;
                    merge(board[nny][nnx], board[ny][nx]);
                }
                q2.push({ny, nx});
                vis[ny][nx] = true;

                if(cnt == k-1) {
                    cout << year << '\n';
                    return 0;
                }
            }
        }
        while(!q2.empty()) {
            auto tmp = q2.front();
            q2.pop();
            q.push(tmp);
        }
    }
}

// 못품 내일 다시..