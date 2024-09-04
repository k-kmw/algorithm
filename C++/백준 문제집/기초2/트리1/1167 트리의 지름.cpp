#include <bits/stdc++.h>
using namespace std;

int n;
vector< pair<int, int> > adjList[100005];
bool vis[100005];
int maxDistV;
int maxDist;

void dfs(int v, int dist) {

    vis[v] = true;

    if(maxDist < dist) {
        maxDist = dist;
        maxDistV = v;
    }

    for(auto u : adjList[v]) {
        if(vis[u.first]) continue;
        dfs(u.first, dist+u.second);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 트리의 지름: 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것
    // 루트에서 ~ 가장 먼 것 노드까지 거리의 최대값
    // 1. 트리를 인집 리스트로 표현
    // 2. dfs 탐색을 하여 depth가 가장 큰 root 노드를 찾는다.
    // 3. root 노드에서 dfs 탐색을 하여 최대 거리를 갱신한다.

    // 위는 틀린 풀이
    // 1. 임의의 노드에서 가장 거리가 먼 노드 u를 찾는다.
    // 2. 노드 u에서 거리가 가장 먼 노드 v까지 거리를 찾으면 트리의 지름
    cin >> n;
    for(int i=0; i<n; i++) {
        int v;
        cin >> v;
        while(true) {
            int u, w;
            cin >> u;
            if(u == -1) {
                break;
            }
            cin >> w;
            adjList[v].push_back(make_pair(u, w));
        }
    }
    dfs(1, 0);
    fill(vis+1, vis+1+n, false);
    dfs(maxDistV, 0);
    cout << maxDist << '\n';
}