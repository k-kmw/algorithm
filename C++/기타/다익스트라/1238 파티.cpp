#include <bits/stdc++.h>
using namespace std;

int dist[1005][1005]; // i를 시작점으로 j번 마을까지 최단 거리
bool vis[1005][1005]; // i를 시작점으로 할 때 방문 배열
vector< pair<int, int> > adjList[1005]; // 가중치, 노드 번호
int n, m, x;

void dijkstra(int st) {
    priority_queue< pair<int, int> > pq; // 거리, 노드 번호
    pq.push(make_pair(0, st));
    dist[st][st] = 0;

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int minVertex = cur.second;

        if(st != x && minVertex == x) {
            return;
        }

        if(vis[st][minVertex]) continue;

        vis[st][minVertex] = true;

        for(auto tmp : adjList[minVertex]) {
            if(dist[st][tmp.second] > dist[st][minVertex] + tmp.first) {
                dist[st][tmp.second] = dist[st][minVertex] + tmp.first;
                pq.push(make_pair(-dist[st][tmp.second], tmp.second));
            }
        }
    }

}

int main() {

    cin >> n >> m >> x;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(w, v));
    }

    for(int i=1; i<=n; i++) {
        fill(dist[i]+1, dist[i]+1+n, 1001*100);
    }

    for(int i=1; i<=n; i++) {
        dijkstra(i);
    }
    dijkstra(x);
    int mx = 0;
    for(int i=1; i<=n; i++) {
        mx = max(mx, dist[i][x] + dist[x][i]);
    }
    cout << mx << '\n';
}