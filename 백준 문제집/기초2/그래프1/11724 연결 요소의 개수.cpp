#include <bits/stdc++.h>
using namespace std;

int n, m;
int adjMatrix[1001][1001];
int vis[1001];

void dfs(int cur) {
    for(int i=1; i<=n; i++) {
        if(vis[i] || adjMatrix[cur][i] == 0)  continue;
        vis[i] = true;
        dfs(i);
    }
}

void bfs(int cur) {
    queue<int> q;
    vis[cur] = true;
    q.push(cur);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(int i=1; i<=n; i++) {
            if(vis[i] || adjMatrix[front][i] == 0)  continue;
            vis[i] = true;
            q.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(vis[i])  continue;
        ans++;
//        dfs(i);
        bfs(i);
    }
    cout << ans << '\n';
}