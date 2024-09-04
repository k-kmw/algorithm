#include <bits/stdc++.h>
using namespace std;

int n, d;
vector< pair<int, int> > adjList[10005];
int dist[10005];
bool vis[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;
    for(int i=0; i<n; i++) {
        int st, en, w;
        cin >> st >> en >> w;
        adjList[st].push_back(make_pair(w, en)); // 지름길 그래프 만들기
    }

    fill(dist, dist+d+1, INT_MAX);

    priority_queue< pair<int, int> > pq; // 가중치, 노드
    pq.push(make_pair(0, 0));
    dist[0] = 0;

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int minVertex = cur.second;

//        cout << minVertex << ' ' << dist[minVertex] << '\n';

        if(minVertex == d) { // 목적지에 도달하면 종료
            cout << dist[minVertex] << '\n';
            return 0;
        }

        if(vis[minVertex]) continue;

//        if(dist[minVertex+1] > dist[minVertex]+1) { // 지름길로 이동하지 않는 경우
//            dist[minVertex+1] = min(dist[minVertex+1], dist[minVertex]+1);
//            pq.push(make_pair(-(dist[minVertex]+1), minVertex+1));
//        }
        dist[minVertex+1] = dist[minVertex]+1;
        pq.push(make_pair(-(dist[minVertex]+1), minVertex+1));

        for(auto tmp : adjList[minVertex]) { // 지름길로 이동하는 경우
            if(tmp.second <= d && dist[tmp.second] > dist[minVertex] + tmp.first) {
                dist[tmp.second] = dist[minVertex] + tmp.first;
                pq.push(make_pair(-dist[tmp.second], tmp.second));
            }
        }
    }
}