#include <bits/stdc++.h>

using namespace std;

int r, c;
char board[1505][1505];
int waterMap[1505][1505];
bool vis[1505][1505];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int num = 1;
vector< pair<int, int> > duck;
int p[3000000];

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    vis[y][x] = true;
    waterMap[y][x] = num; // 해당 좌표의 물 영역의 번호를 기록
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (board[ny][nx] == 'X' || vis[ny][nx]) continue;
            waterMap[ny][nx] = num; // 해당 좌표의 물 영역 번호를 기록
            q.push(make_pair(ny, nx));
            vis[ny][nx] = true;
        }
    }
}

void make_set() {
    for (int i = 0; i < r * c; i++) {
        p[i] = i;
    }
}

int find(int n) {
    if (n == p[n]) return n;
    return p[n] = find(p[n]);
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) return;
    p[rootA] = rootB;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'L') {
                duck.push_back(make_pair(i, j));
            }
        }
    }

    make_set();

    // 1. 물 공간 번호 매기기
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'X' || vis[i][j]) continue;
            bfs(i, j);
            num++;
        }
    }

    // 초기 물 공간 큐에 넣기
    queue<pair<int, int> > q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'X') continue;
            q.push(make_pair(i, j));
            vis[i][j] = true;
        }
    }

    int days = 0;
    while (true) {
        // 4. 두 백조가 동일한 물공간에 있는지 확인
        if (find(waterMap[duck[0].first][duck[0].second]) == find(waterMap[duck[1].first][duck[1].second])) {
            cout << days << '\n';
            return 0;
        }

        // 2. 물 공간 확산
        int qsize = q.size();
        while (qsize--) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (board[ny][nx] != 'X') continue;
                q.push(make_pair(ny, nx));
                waterMap[ny][nx] = waterMap[cur.first][cur.second];
                board[ny][nx] = '.';
            }
        }

        // 3. 인접한 물 공간 확인 후 union
        qsize = q.size();
        while (qsize--) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (board[ny][nx] == 'X' || waterMap[ny][nx] == waterMap[cur.first][cur.second]) continue;
                merge(waterMap[ny][nx], waterMap[cur.first][cur.second]);
            }
            q.push(make_pair(cur.first, cur.second));
        }

//        cout << days << '\n';
//        for (int i = 0; i < r; i++) {
//            for (int j = 0; j < c; j++) {
//                cout << waterMap[i][j];
//            }
//            cout << '\n';
//        }
//        cout << '\n';

        days++;
    }
}