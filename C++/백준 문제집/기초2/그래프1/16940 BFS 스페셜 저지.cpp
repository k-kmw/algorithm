#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adjList[100001];
bool vis[100001];
pair<int, int> dist[100001]; // 거리, 같은 거리 내 순서
int orders[100001];

bool comp(int &a, int &b) {
    return orders[a] < orders[b];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        orders[num] = i;
    }

    for(int i=1; i<=n; i++) {
        sort(adjList[i].begin(), adjList[i].end(), comp);
//        for(int v : adjList[i]) {
//            cout << v << ' ';
//        }
//        cout << '\n';
    }

    bool isCorrect = true;
    queue<int> q; // 노드 번호
    q.push(1);
    vis[1] = true;
    if(orders[1] != 1) {
        isCorrect = false;
        q.pop();
    }
    int seq = 2;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int v : adjList[cur]) {
            if (vis[v])	continue;
            vis[v] = true;
            if(seq != orders[v]) {
                isCorrect = false;
            }
            seq++;
            q.push(v);
        }
    }
    if(isCorrect) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}