#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adjList[100005];
int p[100005];
bool vis[100005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<n; i++) { // 입력으로 주어진 노드 둘 중 어느 것이 부모인지 알 수 없으므로 양방향으로 관계를 맺음
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // 바로 직전에 탐색한 노드가 부모 이므로 BFS를 사용
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int vertex : adjList[cur]) { // 현재 노드에 연결된 노드를 순회
            if(vis[vertex]) continue;  // 연결된 노드인데 이미 방문 되었다면 부모 노드임. 그려보면서 이해
            q.push(vertex);
            p[vertex] = cur;
            vis[vertex] = true;
        }
    }

    for(int i=2; i<=n; i++) {
        cout << p[i] << '\n';
    }
}