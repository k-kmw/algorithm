#include <bits/stdc++.h>
using namespace std;

int n;
int r1, c1, r2, c2;
int dy[] = {-2, -2, 0, 0, 2, 2};
int dx[] = {-1, 1, -2, 2, -1, 1};
int dist[205][205];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    queue< pair<int, int> > q;
    q.push(make_pair(r1, c1));
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<6; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >=n) continue;
            if(dist[ny][nx] != 0) continue;
            dist[ny][nx] = dist[cur.first][cur.second] + 1;
            if(ny == r2 && nx == c2) {
                cout << dist[ny][nx];
                return 0;
            }
            q.push(make_pair(ny, nx));
        }
    }
    cout << -1;
}