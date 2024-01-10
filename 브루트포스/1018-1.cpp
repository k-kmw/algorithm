#include <bits/stdc++.h>
using namespace std;
char board[51][51];

int blackFirst(int i, int j) {
    int cnt = 0;
    for(int k=i; k<i+8; k++) {
        for(int l=j; l<j+8; l++) {
            if((k+l)%2 == 0 && board[k][l] != 'B' || (k+l)%2 != 0 && board[k][l] != 'W') {
                cnt++;
            }
        }
    }
    return cnt;
}

int whiteFirst(int i, int j) {
    int cnt = 0;
    for(int k=i; k<i+8; k++) {
        for(int l=j; l<j+8; l++) {
            if((k+l)%2 == 0 && board[k][l] != 'W' || (k+l)%2 != 0 && board[k][l] != 'B') {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    int mn = 8*8;
    for(int i=0; i<n-8+1; i++) {
        for(int j=0; j<m-8+1; j++) {
            mn = min({blackFirst(i, j), whiteFirst(i, j), mn});
        }
    }

    cout << mn;
}