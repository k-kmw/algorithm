#include <bits/stdc++.h>
using namespace std;
bool vis[9];
int n, m;
vector<int> vec;

void dfs(int k) {
    if(k == m) {
        for (const auto &v: vec) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        vis[i] = true;
        vec.push_back(i);
        dfs(k+1);
        vis[i] = false;
        vec.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dfs(0);
}