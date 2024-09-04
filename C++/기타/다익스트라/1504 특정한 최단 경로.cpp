#include <bits/stdc++.h>
using namespace std;

int dist[805][805]; // 시작점이 i번이고 도착점이 j번인 최소 거리
int vis[805][805]; // 출발점이 i일 때 vis배열 관리
int n, e;
vector< pair<int, int> > adjList[805]; // 가중치, 노드 번호

void dijkstra(int st) {
    priority_queue< pair<int, int> > pq; // 거리, 노드 번호
    pq.push(make_pair(0, st));
    dist[st][st] = 0;

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int minVertex = cur.second;

        // if(vis[st][minVertex]) continue; // v1과 v2를 꼭 거쳐야 하므로 그래프 모양에 따라 왔던 길을 반복 하는게 최단일 수 있음

        // vis[st][minVertex] = true;

        for(auto tmp : adjList[minVertex]) {
            if(dist[st][tmp.second] > dist[st][minVertex] + tmp.first) {
                dist[st][tmp.second] = dist[st][minVertex] + tmp.first;
                pq.push(make_pair(dist[st][tmp.second], tmp.second));
            }
        }
    }
}

int main() {

    // 다익스트라 3개의 시작점에서 수행
    // 1번 케이스
    // 1 -> a
    // a -> b
    // b -> n

    // 2번 케이스
    // 1 -> b
    // b -> a
    // a -> n
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(w, v));
        adjList[v].push_back(make_pair(w, u));
    }
    int v1, v2;
    cin >> v1 >> v2;

    for(int i=1; i<=n; i++) {
        fill(dist[i]+1, dist[i]+1+n, 2400*1001); // 최단 거리로 이동하기 위해서는 하나의 노드를 최대 3번까지 이동 가능
    }

    dijkstra(1);
    dijkstra(v1);
    dijkstra(v2);

    int ans = dist[1][v1] + dist[v1][v2] + dist[v2][n];
    ans = min(ans, dist[1][v2] + dist[v2][v1] + dist[v1][n]);
    if(ans >= 2400*1001) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
}