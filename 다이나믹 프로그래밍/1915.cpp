#include <bits/stdc++.h>
using namespace std;
string board[1001];
int dp[1001][1001];
int ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
            cin >> board[i];

    for(int i=0; i<n; i++) {
        dp[i][0] = board[i][0] - '0';
        ans = max(ans, dp[i][0]);
    }
    for(int j=0; j<m; j++) {
        dp[0][j] = board[0][j] - '0';
        ans = max(ans, dp[0][j]);
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(board[i][j] == '1') {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans * ans;
//    for(int i=0; i<n; i++) {
//        for(int j=0; j<m; j++) {
//            cout << dp[i][j] << ' ';
//        }
//        cout << '\n';
//    }
}