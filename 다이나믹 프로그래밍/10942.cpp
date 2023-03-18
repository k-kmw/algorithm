#include <bits/stdc++.h>
using namespace std;
int num[2001];
int dp[2001][2001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> num[i];

    for(int i=1; i<=n; i++) {
        dp[i][i] = 1;
        if(i != 1 && num[i-1] == num[i]) {
            dp[i-1][i] = 1;
        }
    }

    for(int i=2; i<=n; i++) {
        for(int j=1; i+j <= n; j++) {
            if(num[j] == num[i+j] && dp[j+1][i+j-1])
                dp[j][i+j] = 1;
        }
    }

    cin >> m;
    while(m--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}