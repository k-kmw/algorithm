#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10];
int ans[10];

void dfs(int k, int st) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int prior = 0;
    for (int i = st; i < n; i++) {
        if (a[i] == prior)	continue;
        ans[k] = a[i];
        prior = a[i];
        dfs(k + 1, i+1);
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
    dfs(0, 0);
}