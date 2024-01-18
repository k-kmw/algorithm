#include <bits/stdc++.h>
using namespace std;
int g[10001];
int d[10001][3]; // i번째까지 j잔을 연속으로 마셨을 때, 최대로 마신 포도주의 양

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> g[i];
    }
    d[1][1] = g[1];
    for(int i=2; i<=n; i++) {
        d[i][0] = max({d[i-1][0], d[i-1][1], d[i-1][2]});
        d[i][1] = d[i-1][0] + g[i];
        d[i][2] = d[i-1][1] + g[i];
    }
    cout << max({d[n][0], d[n][1], d[n][2]}) << '\n';
}