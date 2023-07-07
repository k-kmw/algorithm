#include <bits/stdc++.h>
using namespace std;
long long d[101][10]; // d[i][j]: 끝 자리가 j인 i자리 계단 수의 갯수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long ans = 0;

    for(int j=1; j<=9; j++) {
        d[1][j] = 1;
        if(n == 1) {
            ans += d[1][j];
        }
    }

    for(int i=2; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            if(j == 0) d[i][0] = d[i-1][1] % 1000000000;
            else if(j == 9) d[i][9] = d[i-1][8] % 1000000000;
            else {
                d[i][j] = d[i-1][j-1] + d[i-1][j+1] % 1000000000;
            }

            if(i == n) {
                ans += d[i][j];
            }
        }
    }
    cout << ans%1000000000;
}