#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10];
int ans[10];
bool isused[10];

void dfs(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int prior = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == prior || isused[i])	continue;
        ans[k] = a[i];
        prior = a[i];
        isused[i] = true;
        dfs(k + 1);
        isused[i] = false;
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