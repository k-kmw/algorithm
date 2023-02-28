#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 2, 3};
int n;

void bfs() {
    queue<pair<int, int>> q;
    q.push({n, 0});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur.first == 1) {
            cout << cur.second;
            return;
        }

        for(int dir=0; dir<3; dir++) {
            if(dir == 0) {
                q.push({cur.first - dx[dir], cur.second + 1});
            }
            else {
                if(cur.first % dx[dir] == 0) {
                    q.push({cur.first / dx[dir], cur.second + 1});
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    bfs();
}

//bfs 풀이 시간복잡도 3^k?
//큐를 이용하므로 무조건 거리가 가까운 순으로..