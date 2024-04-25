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
    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int vertex : adjList[cur]) {
            if(vis[vertex]) continue;
            q.push(vertex);
            p[vertex] = cur;
            vis[vertex] = true;
        }
    }

    for(int i=2; i<=n; i++) {
        cout << p[i] << '\n';
    }
}