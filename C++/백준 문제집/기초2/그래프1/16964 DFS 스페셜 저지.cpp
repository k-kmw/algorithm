#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100005];
bool vis[100005];
int orders[100005];
int n;
bool isCorrect = true;
int seq;

void dfs(int x) {
    if(vis[x]) {
        return;
    }
    vis[x] = true;
    if(orders[x] != seq) {
        isCorrect = false;
        return;
    }
    seq++;
    for(int v : adjList[x]) {
        if(!isCorrect) {
            return;
        }
        if(vis[v]) continue;
        dfs(v);
    }
}

bool comp(const int& a, const int& b) {
    return orders[a] < orders[b];
}

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

    for(int i=1; i<=n; i++) {
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

    if(orders[1] != 1) {
        isCorrect = false;
        cout << 0 << '\n';
        return 0;
    }

    seq = 1;
    dfs(1);
    if(isCorrect) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}