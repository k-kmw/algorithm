#include <bits/stdc++.h>
using namespace std;
int d[1001][11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int j = 0; j <= 9; j++) {
        d[1][j] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int l = j; l <= 9; l++) {
                d[i][j] = (d[i][j] + d[i - 1][l]) % 10007;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= 9; j++) {
        ans = (ans + d[n][j]) % 10007;
    }
    cout << ans << '\n';
}