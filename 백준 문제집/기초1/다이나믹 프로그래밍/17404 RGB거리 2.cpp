#include <bits/stdc++.h>
using namespace std;
int r[1001];
int g[1001];
int b[1001];
int d[1001][3][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> r[i] >> g[i] >> b[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                d[i][j][k] = 1001*1000;
            }
        }
    }
    d[1][0][0] = r[1];
    d[1][1][1] = g[1];
    d[1][2][2] = b[1];

    for(int i=2; i<=n; i++) {
        d[i][0][0] = min(d[i-1][1][0], d[i-1][2][0]) + r[i];
        d[i][0][1] = min(d[i-1][1][1], d[i-1][2][1]) + r[i];
        d[i][0][2] = min(d[i-1][1][2], d[i-1][2][2]) + r[i];

        d[i][1][0] = min(d[i-1][0][0], d[i-1][2][0]) + g[i];
        d[i][1][1] = min(d[i-1][0][1], d[i-1][2][1]) + g[i];
        d[i][1][2] = min(d[i-1][0][2], d[i-1][2][2]) + g[i];

        d[i][2][0] = min(d[i-1][0][0], d[i-1][1][0]) + b[i];
        d[i][2][1] = min(d[i-1][0][1], d[i-1][1][1]) + b[i];
        d[i][2][2] = min(d[i-1][0][2], d[i-1][1][2]) + b[i];
    }

    cout << min({d[n][1][0], d[n][2][0],
                 d[n][0][1], d[n][2][1],
                 d[n][0][2], d[n][1][2]}) <<'\n';
}