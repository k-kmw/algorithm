#include <bits/stdc++.h>
using namespace std;

int board[301][301];
int dist[301][301];
int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int l;
        cin >> l;
        for(int i=0; i<l; i++)
            fill(dist[i], dist[i]+l, -1);
        int sx, sy;
        cin >> sx >> sy;
        int fx, fy;
        cin >> fx >> fy;

        queue<pair<int, int>> q;
        dist[sx][sy] = 0;
        q.push({sx, sy});
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(int dir=0; dir<8; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l)  continue;
                if(dist[nx][ny] != -1)  continue;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }

        cout << dist[fx][fy] << '\n';
    }


}


