#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[20001];
int colors[20001];
bool isBipartite;
int V, E;

void bfs(int cur, int color) {
    queue<int> q;
    q.push(cur);
    colors[cur] = color;

    while(!q.empty() && isBipartite) {
        int node = q.front();
        q.pop();
        for(int adjV : adjList[node]) {
            if(colors[adjV] == 0) { // 방문하지 않은 정점이면
                colors[adjV] = colors[node] * -1;
                q.push(adjV);
            } else if(colors[node] + colors[adjV] != 0) { // 방문한 정점인데 인접한 노드와 색이 다르지 않으면
                isBipartite = false; // 이분 그래프가 아님
                return;
            }
        }
    }
}

void dfs(int cur, int color) {
    colors[cur] = color;
    for(int node : adjList[cur]) {
        if(colors[node] == 0) {
            colors[node] = colors[cur] * -1;
            dfs(node, colors[node]);
        } else if(colors[cur] + colors[node] != 0) {
            isBipartite = false;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    for(int test_case=1; test_case<=T; test_case++) {
        cin >> V >> E;
        for(int i=1; i<=V; i++) {
            adjList[i].clear();
        }
        fill(colors+1, colors+1+V, 0);
        isBipartite = true;
        while(E--) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for(int i=1; i<=V; i++) {
            if(!isBipartite) {
                cout << "NO" << '\n';
                break;
            }
            if(colors[i] == 0) {
//                bfs(i, 1); // 처음 색깔 1(RED)
                dfs(i, 1);
            }
        }
        if(isBipartite) {
            cout << "YES" << '\n';
        }
    }
}