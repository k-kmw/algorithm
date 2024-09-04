#include <bits/stdc++.h>
using namespace std;

int coins[101];
int d[2][100001];
int n, k;
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }

    sort(coins, coins + n);

    d[0][0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<=k; j++) {
            int coin = coins[i];
            if(coin > j) {
                d[1][j] = d[0][j];
            } else {
                d[1][j] = d[0][j] + d[1][j-coin];
            }
//            cout << coin << ' ' << j << ' ' << d[1][j] << '\n';
        }
        copy(d[1], d[1]+k+1, d[0]);
    }
    cout << d[1][k] << '\n';
}