#include <bits/stdc++.h>
using namespace std;
int s[2][100001];
int d[100001][3]; // i번째 칸에서 j번 방법으로 선택했을 때, 최대값
// 0번:ox, 1번: xo, 2번: xx

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 2; i++)
            fill(s[i], s[i] + n, 0);
        for (int i = 1; i <= n; i++)
            fill(d[i], d[i] + 3, 0);

        for(int i=0; i<2; i++) {
            for(int j=1; j<=n; j++) {
                cin >> s[i][j];
            }
        }
        d[1][0] = s[0][1];
        d[1][1] = s[1][1];
        d[1][2] = 0;

        for (int i = 2; i <= n; i++) {
            d[i][0] = max(d[i - 1][1], d[i - 1][2]) + s[0][i];
            d[i][1] = max(d[i - 1][0], d[i - 1][2]) + s[1][i];
            d[i][2] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] });
        }
         cout << max({ d[n][0], d[n][1], d[n][2] }) << '\n';
    }
}