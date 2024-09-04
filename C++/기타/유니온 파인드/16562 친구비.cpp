#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[10005];
int vis[10005];
int p[10005];
int cost[10005];

void make_set() {
    for(int i=1; i<=n; i++) {
        p[i] = i;
    }
}

int find(int v) {
    if(v == p[v]) return v;
    return p[v] = find(p[v]);
}

void merge(int v, int w) {
    int rootA = find(v);
    int rootB = find(w);
    if(rootA == rootB) {
        return;
    }
    cost[rootB] = min(cost[rootB], cost[rootA]);
    cost[rootB] = min(min(a[v], a[w]), cost[rootB]);
    p[rootA] = rootB;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 유니온 파인드하면서 각 그룹의 친구비 최소값 구하기
    // 2. 친구 1번부터 n번까지 순회하면서 친구비 더하기. 만약 이미 친구이면 continue
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        cost[i] = a[i];
    }
    make_set();
    for(int i=0; i<m; i++) {
        int v, w;
        cin >> v >> w;
        merge(v, w);
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        int root = find(i);
        if(vis[root])    continue;
        ans += cost[root];
        vis[root] = true;
//        cout << i << " " << root << " " << cost[root] << '\n';
//        cout << ans << '\n';
    }
    if(ans > k) {
        cout << "Oh no" << '\n';
        return 0;
    }
    cout << ans << '\n';
}