#include <bits/stdc++.h>
using namespace std;
int pre[3005];
bool vis[3005];
bool cycle[3005];
int dist[3005];
vector<int> adjList[3005];
bool isCycle;
int n;

void dfs(int cur, int st, int cnt) {
    vis[cur] = true;
    for (int v : adjList[cur]) {
        if (isCycle) {
            return;
        }
        if (vis[v]) {
            if (v == st && cnt > 2) {
                isCycle = true;
                cycle[v] = true;
                int node = cur;
                while (node != v) {
                    cycle[node] = true;
                    node = pre[node];
                }
                return;
            }
        }
        else {
            pre[v] = cur;
            dfs(v, st, cnt + 1);
        }
    }
}

void bfs() {

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        if (cycle[i]) {
            q.push({ i, 0 });
            vis[i] = true;
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int v : adjList[cur.first]) {
            if (vis[v]) continue;
            dist[v] = cur.second + 1;
            vis[v] = true;
            q.push({ v, cur.second + 1 });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // 사이클 찾기
    for (int i = 1; i <= n; i++) {
        dfs(i, i, 1);
        fill(vis + 1, vis + n + 1, false);
    }

    // 각 역에서 최단거리 찾기
    bfs();

    for (int i = 1; i <= n; i++) {
        //cout << "cycle: " << cycle[i] << '\n';
        cout << dist[i] << " ";
    }
}