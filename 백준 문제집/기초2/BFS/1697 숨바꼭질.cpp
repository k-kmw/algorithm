#include <bits/stdc++.h>
using namespace std;
bool vis[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    queue<pair<int, int >> q; // 좌표, 시간
    q.push({ n, 0 });
    vis[n] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.first == k) {
            cout << cur.second << '\n';
            return 0;
        }
        for (int nx : {cur.first - 1, cur.first + 1, cur.first * 2}) {
            if (nx < 0 || nx > 100000 || vis[nx])	continue;
            q.push({ nx, cur.second + 1 });
            vis[nx] = true;
        }
    }
}