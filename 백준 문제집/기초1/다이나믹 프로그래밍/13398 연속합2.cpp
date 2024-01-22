#include <bits/stdc++.h>
using namespace std;
int a[100001];
int d[100001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    d[1][0] = a[1];
    d[1][1] = a[1];
    for (int i = 2; i <= n; i++) {
        d[i][0] = max(d[i - 1][0] + a[i], a[i]);
        d[i][1] = max(d[i - 1][0], d[i - 1][1] + a[i]);
    }
    int mx = INT_MIN;
    for (int i = 1; i <= n; i++) {
        mx = max({ mx, d[i][0], d[i][1] });
    }
    cout << mx << '\n';
}
// 다시 풀기.