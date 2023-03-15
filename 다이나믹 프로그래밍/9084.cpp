//#include <bits/stdc++.h>
//using namespace std;
//int dp[10001];
//int coin[21];
//int n, m;
//
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    int t;
//    cin >> t;
//    while(t--) {
//        cin >> n;
//        for(int i=0; i<n; i++)  cin >> coin[i];
//        cin >> m;
//
//        dp[0] = 1;
//        for(int i=1; i<=m; i++) {
//            for(int j=0; j<n; j++) {
//                if(coin[j] <= i)
//                    dp[i] += dp[i - coin[j]];
//                cout << j << ' ' << dp[i] << ' ';
//            }
//            cout << '\n';
//        }
//        cout << dp[m] << '\n';
//    }
//
//}
// 못풀겠음 다음에 도전..
