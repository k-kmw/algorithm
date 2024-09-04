#include <bits/stdc++.h>
using namespace std;

int d[100001][3]; // i번째 행에 j 번째 방법으로 배치할떄 경우의 수
// 방법에는 ox, xo, xx 3가지 방법이 있음
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;
    for(int i=2; i<=n; i++) {
        d[i][0] = (d[i-1][1] + d[i-1][2]) % 9901;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % 9901;
        d[i][2] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % 9901;
    }
    cout << (d[n][0] + d[n][1] + d[n][2]) % 9901;
}