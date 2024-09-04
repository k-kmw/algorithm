#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10];
int ans[10];

void dfs(int k) {

    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << a[ans[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    int st = 0;
    if(k != 0)
        st = ans[k - 1];
    for (int i = st; i < n; i++) {
        ans[k] = i;
        dfs(k + 1);
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