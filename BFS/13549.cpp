#include <bits/stdc++.h>
using namespace std;

int dist[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    queue<int> q;
    fill(dist, dist+100001, -1);

    q.push(n);
    dist[n] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int nx : {cur*2, cur-1, cur+1}) { // 우선순위가 cur*2가 높으므로, cur*2를 먼저 큐에 push함
            if(nx < 0 || nx > 100000 || dist[nx] >= 0)   continue;
            if(nx == cur*2) {
                dist[nx] = dist[cur];
            }
            else {
                dist[nx] = dist[cur] + 1;
            }
            if(nx == k) {
                cout << dist[nx];
                return 0;
            }
            q.push(nx);
        }
    }
    cout << 0;
}


