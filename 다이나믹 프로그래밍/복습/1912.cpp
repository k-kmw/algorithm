#include <bits/stdc++.h>
using namespace std;
int d[100001][2];
int a[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    d[1][1] = a[1];
    d[1][0] = -1001;
    for(int i=2; i<=n; i++) {
        d[i][0] = max(d[i-1][0], d[i-1][1]);
        d[i][1] = max(d[i-1][1]+a[i], a[i]);
//        cout << max(d[i][0], d[i][1]) << '\n';
    }
    cout << max(d[n][0], d[n][1]);
}