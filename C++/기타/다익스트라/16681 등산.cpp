#include <bits/stdc++.h>
using namespace std;

int n, m, d, e;
long long dist[100005][2]; // 집 ~ 모든 지점, 고려대 ~ 모든 지점
int vis[100005][2];
int h[100005];
vector<pair<long long, int>> adjList[100005]; // 거리, 노드 번호
priority_queue<pair<long long, int>> pq; // 거리 , 노드 번호

int main() {
    cin >> n >> m >> d >> e;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({ w, v });
        adjList[v].push_back({ w, u });
    }

    for (int i = 1; i <= n; i++) {
        fill(dist[i], dist[i] + 2, 100000 * 100001LL);
    }

    // 1. 집에서 다익스트라 + 높이 제약
    pq.push({ 0, 1 });
    dist[1][0] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int minVertex = cur.second;

        if (vis[minVertex][0])	continue;

        vis[minVertex][0] = true;

        for (auto tmp : adjList[minVertex]) {
            if (dist[tmp.second][0] > dist[minVertex][0] + tmp.first &&  h[minVertex] < h[tmp.second]) {
                dist[tmp.second][0] = dist[minVertex][0] + tmp.first;
                pq.push({ -dist[tmp.second][0], tmp.second});
            }
        }
    }

    //for (int i = 1; i <= n; i++) {
    //	cout << dist[i][0] << ' ';
    //}
    //cout << '\n';

    // 2. 고려대에서 다익스트라 + 높이 제약
    pq.push({ 0, n });
    dist[n][1] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int minVertex = cur.second;

        if (vis[minVertex][1])	continue;

        vis[minVertex][1] = true;

        for (auto tmp : adjList[minVertex]) {
            if (dist[tmp.second][1] > dist[minVertex][1] + tmp.first && h[minVertex] < h[tmp.second]) {
                dist[tmp.second][1] = dist[minVertex][1] + tmp.first;
                pq.push({ -dist[tmp.second][1], tmp.second });
            }
        }
    }

    //for (int i = 1; i <= n; i++) {
    //	cout << dist[i][1] << ' ';
    //}
    // cout << '\n';

    // 3. 두 지점 합해서 최대 가치 구하기
    long long mx = LONG_MIN;
    for (int i = 2; i < n; i++) {
        if (dist[i][0] == 100000 * 100001LL || dist[i][1] == 100000 * 100001LL)	continue;
        long long candidate = h[i] * e - (dist[i][0] + dist[i][1])*d;
        mx = max(mx, candidate);
    }
    if (mx == LONG_MIN) {
        cout << "Impossible" << '\n';
        return 0;
    }
    cout << mx << '\n';
}