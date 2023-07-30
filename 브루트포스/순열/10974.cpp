#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[9];
vector<int> vec;

void dfs(int k) {
    if(k == n) {
        for (const auto &v: vec) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        vec.push_back(i);
        vis[i] = true;
        dfs(k+1);
        vec.pop_back();
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dfs(0);
}