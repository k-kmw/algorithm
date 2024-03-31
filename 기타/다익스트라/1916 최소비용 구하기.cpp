#include <bits//stdc++.h>
using namespace std;

int n, m;
vector< pair<int, int> > adjList[1005]; // 노드 번호, 가중치 인접 리스트
int src, dest;
int dist[1005];
bool vis[1005];
priority_queue< pair<int, int> > pq; // 거리, 노드 번호

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(v, w));
    }
    cin >> src >> dest;

    // 다익스트라
    // 1. 출발점에서 최소 노드 찾기
    // 2. 최소 노드를 이용하여 거리 갱신

    fill(dist+1, dist+1+n, 1001*100000);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int minVertex = cur.second;
//        cout << minVertex << '\n';

        if(minVertex == dest) {
            break;
        }

        if(vis[minVertex]) continue;

        vis[minVertex] = true;

        // minVertex 경유하여 최소값 갱신
        for(auto tmp : adjList[minVertex]) {
            if(dist[tmp.first] > dist[minVertex] + tmp.second) {
                dist[tmp.first] = dist[minVertex] + tmp.second;
                pq.push(make_pair(-dist[tmp.first], tmp.first));
            }
        }
    }

    cout << dist[dest] << '\n';
}