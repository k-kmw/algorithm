#include <bits/stdc++.h>
using namespace std;

int dist[505];
bool vis[505];
bool check[505];
bool rm[505][505];
vector<pair<int, int>> adjList[505]; // 가중치, 노드 번호
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
        adjList->clear();
        fill(check, check+n, false);
        int s, d;
        cin >> s >> d;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back({ w, v });
        }

        fill(dist, dist + n, 501 * 1000);
        fill(vis, vis + n, false);
        for (int i = 1; i <= n; i++) {
            fill(rm[i] + 1, rm[i] + n + 1, false);
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
                }

            }
        }

//        for (int i = 0; i < n; i++) {
//            cout << dist[i] << ' ';
//        }
//        cout << '\n';

        // 2. 최단거리에 포함되는 경로 제거
        queue<pair<pair<int, int>, vector<int>>> q; // 노드 번호, 가중치 합, 경로
        vector<int> v;
        v.push_back(s);
        q.push({{s, 0}, v});
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            int node = cur.first.first;
            int sum = cur.first.second;

//            cout << node << '\n';

            if(node == d && sum == dist[d]) {
                auto path = cur.second;
                for(int i=1; i<path.size(); i++) {
                    int prior = path[i-1];
                    int vertex = path[i];
//                    cout << prior << ' ' << vertex << '\n';
                    rm[prior][vertex] = true;
                }
            }
//
//            if(check[node]) continue;
//            check[node] = true;

            for(auto tmp : adjList[node]) {
                if(dist[node] + tmp.first == dist[tmp.second]) {
//                    cout << "test" << tmp.second << '\n';
                    vector<int> newPath(cur.second);
                    newPath.push_back(tmp.second);
                    q.push({{tmp.second, sum+tmp.first}, newPath});
                }
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
//                cout << "TEST: " << minVertex << ' ' << tmp.second << '\n';
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