#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10];
vector<int> vec;

void dfs(int k) {
    if (k == m) {
        for (auto v : vec) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        vec.push_back(a[i]);
        dfs(k + 1);
        vec.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    dfs(0);
}