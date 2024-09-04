#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[1005][1005];
bool defect[1005][1005];
bool vis[1005][1005];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 바이러스 살포된 곳을 큐에 넣음 (좌표, 전파 지연 시간, 진행 시간)
    // 2. bfs 수행하면서 전파
    // 3. 건물이면 퍼지는 시간을 큐에 같이 넣기
    // 4. 큐에서 꺼냈을 때 건물이면 전파 지연 시간이 0인지 확인하고 아니면 1을 뺴고 큐에 다시 넣기
    int tg, tb, X, b;
    cin >> n >> m;
    cin >> tg >> tb >> X >> b;

    queue<pair<int, int>> q;
    queue<pair<pair<int, int>, int>> buildingQ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == '*') {
                q.push({i, j});
                defect[i][j] = true;
            }
        }
    }
    int t = 0;
    while (true) {

//        int qsize = buildingQ.size();
//        while(qsize--) {
//            auto cur = buildingQ.front();
//            buildingQ.pop();
//            if(cur.second == 0) {
//                q.push({cur.first.first, cur.first.second});
//                defect[cur.first.first][cur.first.second] = true;
//            } else {
//                buildingQ.push({{cur.first.first, cur.first.second}, cur.second-1});
//            }
//        }

        while(!buildingQ.empty() && buildingQ.front().second == t) {
            auto building = buildingQ.front();
            buildingQ.pop();
            defect[building.first.first][building.first.second] = true;
            q.push({building.first.first, building.first.second});
        }

        if (t == tg) {
            break;
        }

        int qsize = q.size();
        while(qsize--) {
            auto cur = q.front();
            q.pop();
            int y = cur.first;
            int x = cur.second;

//            cout << t << '\n';
//            cout << y << ' ' <<  x << '\n';

            for (int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (ny >= n || ny < 0 || nx >= m || nx < 0)	continue;
                if (defect[ny][nx] || vis[ny][nx])	continue;
                if (board[ny][nx] == '#') {
                    buildingQ.push({ {ny, nx}, t+tb+1 });
                    vis[ny][nx] = true;
                }
                else {
                    q.push({ny, nx});
                    defect[ny][nx] = true;
                }
            }
        }

        t++;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!defect[i][j]) {
                cnt++;
                cout << i+1 << ' ' << j+1 << '\n';
            }
        }
    }
    if (cnt == 0) {
        cout << -1 << '\n';
    }
}