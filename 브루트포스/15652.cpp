#include <bits/stdc++.h>
using namespace std;
bool vis[9];
int n, m;
vector<int> vec;

void dfs(int k, int st) {
    if(k == m) {
        for (const auto &v: vec) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=st; i<=n; i++) {
        vec.push_back(i);
        dfs(k+1, i);
        vec.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dfs(0, 1);
}