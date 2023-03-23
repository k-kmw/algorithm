#include <bits/stdc++.h>
using namespace std;
int dp[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++) {
        dp[i] = min(dp[i-3], dp[i-1]) + 1;
    }
    if(dp[n]%2 == 0)
        cout << "CY";
    else
        cout << "SK";
}