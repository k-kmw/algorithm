#include <bits/stdc++.h>
using namespace std;

int n, m;
vector< pair<int, int> > adjList[50005]; // 가중치, 노드 번호
int dist[50005];
bool vis[50005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back(make_pair(c, b));
        adjList[b].push_back(make_pair(c, a));
    }

    fill(dist+1, dist+1+n, INT_MAX);

    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, 1));
    dist[1] = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int minVertex = cur.second;

        if(vis[minVertex]) continue;

//        cout << minVertex << ' ' << dist[minVertex] << '\n';

        vis[minVertex] = true;

        for(auto tmp : adjList[minVertex]) {
            if(dist[tmp.second] > dist[minVertex] + tmp.first) {
                dist[tmp.second] = dist[minVertex] + tmp.first;
                pq.push(make_pair(-dist[tmp.second], tmp.second));
            }
        }
    }
    cout << dist[n] << '\n';
}