#include <bits/stdc++.h>
using namespace std;

bool vis[100001];
int mn = 100001;
int dist[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    queue< pair<int, int> > q; // 좌표, 시간
    q.push(make_pair(n, 0));
    vis[n] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int t = cur.second;

        if(x == k) {
            cout << t << '\n';
            break;
        }
        if(2*x <= 100000 && !vis[2*x]) { // 2*x 먼저 큐에 넣어야 최소 시간이 됨
            q.push((make_pair(2*x, t)));
            vis[2*x] = true;
        }

        if(x-1 >= 0 && !vis[x-1]) {
            q.push(make_pair(x-1, t+1));
            vis[x-1] = true;
        }

        if(x+1 <= 100000 && !vis[x+1]) {
            q.push((make_pair(x+1, t+1)));
            vis[x+1] = true;
        }
    }
}