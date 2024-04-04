#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adjList[10005];
priority_queue < pair<long long, pair<int, int>>> pq; // 시간, 노드 번호, k 
long long dist[10005][25]; // 노드 번호, k
bool vis[10005][25];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({ w, v });
        adjList[v].push_back({ w, u });
    }

    for (int i = 1; i <= n; i++) {
        fill(dist[i], dist[i] + k + 1, 10001 * 1000000LL);
    }

    // 1번 노드 ~ N번 노드 최단 거리
    pq.push({ 0, {1, 0} });
    dist[1][0] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int t = -cur.first;
        int minVertex = cur.second.first;
        int num = cur.second.second;

        if (vis[minVertex][num])	continue;

        vis[minVertex][num] = true;

        //cout << minVertex << " " << num << " " << t << '\n';

        ;		for (auto tmp : adjList[minVertex]) {
            if (dist[tmp.second][num] > dist[minVertex][num] + tmp.first) {
                dist[tmp.second][num] = dist[minVertex][num] + tmp.first; // 도로 포장 X
                pq.push({ -dist[tmp.second][num], {tmp.second, num} });
            }
            if (num < k) {
                if (dist[tmp.second][num + 1] > dist[minVertex][num]) {
                    dist[tmp.second][num + 1] = dist[minVertex][num]; // 도로 포장
                    pq.push({ -dist[tmp.second][num + 1], {tmp.second, num + 1} });
                }
            }
        }
    }

    long long res = 10001 * 1000000LL;
    for (int j = 0; j <= k; j++) { // k번 이하로 움직여서 n에 도착하는 경우가 있을 수 있으므로, d[n][k]가 무조건 정답이 아님
        res = min(res, dist[n][j]);
    }

    cout << res << '\n';

    //for (int i = 0; i <= k; i++) {
    //	cout << dist[n][i] << ' ';
    //}
    //cout << '\n';
}