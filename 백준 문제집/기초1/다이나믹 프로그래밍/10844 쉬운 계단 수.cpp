#include <bits/stdc++.h>
using namespace std;
int d[101][11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1; i<=9; i++) {
        d[1][i] = 1;
    }
    int n;
    cin >> n;
    for(int i=2; i<=n; i++) {
        d[i][0] = d[i-1][1];
        for(int j=1; j<=9; j++) {
            d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % 1000000000;
        }
    }
    int ans = 0;
    for(int i=0; i<=9; i++) {
        ans = (ans + d[n][i]) % 1000000000;
    }
    cout << ans << '\n';
}