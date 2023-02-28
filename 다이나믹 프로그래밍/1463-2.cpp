#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 2, 3};
int dist[1000001];
int n;

void bfs() {
    queue<int> q;
    dist[n] = 0;
    q.push(n);
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur == 1) {
            cout << dist[cur];
            return;
        }
        else {
            for(int dir=0; dir<3; dir++) {
                int nx;
                if(dir == 0) {
                    nx = cur - dx[dir];
                }
                else {
                    if(cur % dx[dir] == 0) {
                        nx = cur / dx[dir];
                    }
                }
                if(nx < 1)  continue;
                if(dist[nx] == 0) {
                    dist[nx] = dist[cur]+1;
                }
                else
                    continue;
                q.push(nx);
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