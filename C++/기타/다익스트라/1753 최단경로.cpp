#include <bits/stdc++.h>
using namespace std;

int V, E;
int st;
vector< pair<int, int> > adjList[20005]; // 인접 리스트. 연결된 노드 번호, 가중치
priority_queue< pair<int, int> > pq; // 정점 번호, 거리
int dist[20005];
bool vis[20005];
int main() {

    cin >> V >> E;
    cin >> st;
    for(int i=0; i<E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(v, w));
    }

    fill(dist+1, dist+1+V, 200005);

    pq.push(make_pair(0, st));
    dist[st] = 0;
    while(!pq.empty()) {
        // 1. 시작점과 거리가 최소인 정점 찾기
        auto cur = pq.top();
        int minVertex = cur.second;
        pq.pop();
//        cout << minVertex << ' ' << minWeight << '\n';

        if(vis[minVertex]) continue; // 이미 방문한 노드이면 continue

        vis[minVertex] = true;

        for(auto tmp : adjList[minVertex]) { // minVertex를 이용하여 최소값 갱신
//            cout << tmp.first << '\n';
            if(dist[tmp.first] > dist[minVertex] + tmp.second) {
                dist[tmp.first] = dist[minVertex] + tmp.second;
                pq.push(make_pair(-dist[tmp.first], tmp.first )); // 최대힙이므로 -곱해서 넣기
            }
        }
    }

    for(int i=1; i<=V; i++) {
        if(dist[i] == 200005) {
            cout << "INF" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }
}