#include <bits/stdc++.h>
using namespace std;

int n;
vector< pair<int, int> > adjList[100005];
bool vis[100005];
int maxDist;
int maxDistV;

void dfs(int v, int dist) {

    if(dist > maxDist) {
        maxDist = dist;
        maxDistV = v;
    }

    vis[v] = true;

    for(auto u : adjList[v]) {
        if(vis[u.first]) continue;

        dfs(u.first, dist+u.second);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    dfs(1, 0);
    fill(vis+1, vis+1+n, false);
    dfs(maxDistV, 0);
    cout << maxDist << '\n';
}