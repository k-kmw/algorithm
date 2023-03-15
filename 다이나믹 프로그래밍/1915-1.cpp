#include <bits/stdc++.h>
using namespace std;
int board[1001][1001];
int dp[1001][1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            board[i][j] = s[j - 1] - '0';
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j]) {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans * ans;

}