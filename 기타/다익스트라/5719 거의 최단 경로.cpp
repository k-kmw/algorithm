#include <bits/stdc++.h>
using namespace std;

int dist[505];
bool vis[505];
bool check[505];
bool rm[505][505];
vector<pair<int, int>> adjList[505]; // 가중치, 노드 번호
vector<int> pre[505];
priority_queue<pair<int, int>> pq; // 가중치, 노드 번호

int main() {
    // 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것

    // 시작점에서 다익스트라 하면서 최단거리 구하기
    // dist[v] == dist[u] + d[u][v]이면 (u, v)는 최단거리를 구성하는 간선
    // rm[u][v] = true
    // 다시 시작점에서 다익스트라해서 최단거리 찾기

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            adjList[i].clear();
            pre[i].clear();
        }

        int s, d;
        cin >> s >> d;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back({ w, v });
        }

        fill(dist, dist + n, 501 * 1000);
        fill(vis, vis + n, false);
        fill(check, check + n, false);
        for (int i = 0; i < n; i++) {
            fill(rm[i], rm[i] + n, false);
        }

        // 1. 시작점에서 목적지까지 최단거리 구하기 (다익스트라)
        dist[s] = 0;
        pq.push({ 0, s });
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int minVertex = cur.second;

            if (vis[minVertex])    continue;

            vis[minVertex] = true;

            for (auto tmp : adjList[minVertex]) {
                if (dist[tmp.second] > dist[minVertex] + tmp.first) {
                    dist[tmp.second] = dist[minVertex] + tmp.first;
                    pq.push({ -dist[tmp.second], tmp.second });
                    pre[tmp.second].clear();
                    pre[tmp.second].push_back(minVertex);
                }
                else if (dist[tmp.second] == dist[minVertex] + tmp.first) {
                    pre[tmp.second].push_back(minVertex);
                }
            }
        }

//        for (int i = 0; i < n; i++) {
//            cout << dist[i] << ' ';
//        }
//        cout << '\n';

        // 2. 최단거리에 포함되는 경로 제거
        queue<int> q;
        q.push(d);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (check[cur])  continue;

            check[cur] = true;

            for (int prior : pre[cur]) {
                //cout << prior << ' ' << cur << '\n';
                rm[prior][cur] = true;
                q.push(prior);
            }
        }

        // 3. 경로 제거 후 시작점에서 다익스트라
        fill(dist, dist + n, 501 * 1000);
        fill(vis, vis + n, false);

        dist[s] = 0;
        pq.push({ 0, s });
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int minVertex = cur.second;

            if (vis[minVertex])    continue;

            vis[minVertex] = true;

            for (auto tmp : adjList[minVertex]) {
                if (rm[minVertex][tmp.second])    continue;
                if (dist[tmp.second] > dist[minVertex] + tmp.first) {
                    dist[tmp.second] = dist[minVertex] + tmp.first;
                    pq.push({ -dist[tmp.second], tmp.second });
                }
            }
        }
        if (dist[d] == 501 * 1000) {
            cout << -1 << '\n';
        }
        else {
            cout << dist[d] << '\n';
        }
    }
}