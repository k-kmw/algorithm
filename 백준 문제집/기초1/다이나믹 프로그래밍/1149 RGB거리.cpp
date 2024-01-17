#include <bits/stdc++.h>
using namespace std;

int n;
int r[1001];
int g[1001];
int b[1001];
int d[1001][3]; // d[i][0]: i번째 집에 빨강을 칠했을 때, i 번째 집까지 칠하는 최소 비용

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> r[i] >> g[i] >> b[i];
    }
    d[0][0] = r[0];
    d[0][1] = g[0];
    d[0][2] = b[0];
    for(int i=1; i<n; i++) {
        d[i][0] = min(d[i-1][1],d[i-1][2]) + r[i]; // i번째 집에 빨강
        d[i][1] = min(d[i-1][0], d[i-1][2]) + g[i]; // i번째 집에 초록
        d[i][2] = min(d[i-1][0], d[i-1][1]) + b[i]; // i번째 집에 파랑
    }
    cout << min({d[n-1][0], d[n-1][1], d[n-1][2]}) << '\n';
}