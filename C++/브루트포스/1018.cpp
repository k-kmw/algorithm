#include <bits/stdc++.h>
using namespace std;
char board[51][51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    int mn = 8*8;
    for(int i=0; i<=n-8; i++) {
        for(int j=0; j<=m-8; j++) {
            int cnt1 = 0;
            int cnt2 = 0;
            for(int k=i; k<i+8; k++) {
                for(int l=j; l<j+8; l++) {
                    if((k+l)%2 == 0 && board[k][l] != 'B' || (k+l)%2 != 0 && board[k][l] != 'W') { // 맨 왼쪽 위 칸이 검은색인 경우
                        cnt1++;
                    }
                    if((k+l)%2 == 0 && board[k][l] != 'W' || (k+l)%2 != 0 && board[k][l] != 'B') { // 맨 왼쪽 위 칸이 흰색인 경우
                        cnt2++;
                    }
                }
            }
            mn = min({cnt1, cnt2, mn});
        }
    }

    cout << mn;
}