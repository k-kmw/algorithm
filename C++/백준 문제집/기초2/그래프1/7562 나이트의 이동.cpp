#include <bits/stdc++.h>
using namespace std;
int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[] = {-1, 1,-2, 2, -2, 2, -1, 1};
bool vis[301][301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int l;
        cin >> l;
        int sy, sx;
        cin >> sy >> sx;
        int fy, fx;
        cin >> fy >> fx;

        for(int i=0; i<l; i++) {
            fill(vis[i], vis[i]+l, false);
        }
        queue< pair<pair<int, int>, int> > q;
        q.push(make_pair(make_pair(sy, sx), 0));
        vis[sy][sx] = true;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(cur.first.first == fy && cur.first.second == fx) {
                cout << cur.second << '\n';
                break;
            }
            for(int dir=0; dir<8; dir++) {
                int ny = cur.first.first + dy[dir];
                int nx = cur.first.second + dx[dir];
                if(ny < 0 || ny >= l || nx < 0 || nx >= l) continue;
                if(vis[ny][nx]) continue;
                vis[ny][nx] = true;
                q.push(make_pair(make_pair(ny, nx), cur.second+1));
            }
        }
    }
}