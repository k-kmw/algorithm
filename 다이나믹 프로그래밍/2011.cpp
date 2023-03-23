#include <bits/stdc++.h>
using namespace std;
string s;
int a[5001];
int dp[5001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    unsigned int n = s.length();
    if(s[0] == '0') {
        cout << 0;
        return 0;
    }
    for(int i=1; i<=n; i++) {
        a[i] = s[i-1] - '0';
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        if(a[i-1] == 2 && a[i] <= 6 && a[i] > 0 || a[i-1] == 1 && a[i] <= 9 && a[i] > 0) {
            dp[i] = (dp[i-2] + dp[i-1]) % 1000000;
        }
        else if(a[i] == 0 && (a[i-1] != 1 && a[i-1] != 2 )) {
            dp[i] = 0;
        }
        else dp[i] = dp[i-1];
    }

    cout << dp[n];
}
//틀림