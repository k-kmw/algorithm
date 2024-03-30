#include <bits/stdc++.h>
using namespace std;

bool vis[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q; // 위치, 시간
    q.push({n, 0});
    vis[n] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur.first == k) {
            cout << cur.second << '\n';
            break;
        }
        for(int nx : {cur.first+1, cur.first-1, cur.first*2}) {
            if(nx < 0 || nx > 100000)   continue;
            if(vis[nx]) continue;
            if(nx == cur.first*2) {
                q.push({nx, cur.second});
            } else {
                q.push({nx, cur.second+1});
            }
            if(nx == k) {
                cout << cur.second + 1 << '\n';
                return 0;
            }
            vis[nx] = true;
        }
    }
}