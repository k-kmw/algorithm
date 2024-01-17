#include <bits/stdc++.h>
using namespace std;
int d[201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int j=1; j<=k; j++) {
        d[0][j] = 1;
    }
    for(int i=0; i<=n; i++) {
        d[i][1] = 1;
    }
    for(int i=1; i<=n; i++) {
        for(int j=2; j<=k; j++) {
            for(int l=i; l>=0; l--) {
                d[i][j] = (d[i][j] + d[l][j-1]) % 1000000000;
            }
        }
    }
    cout << d[n][k] % 1000000000 << '\n';
}