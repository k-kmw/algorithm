#include <bits/stdc++.h>
using namespace std;
int d[501][501];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> board(n);
    for(int i=0; i<n; i++) {
        for (int j = 0; j < i + 1; j++) {
            int x;
            cin >> x;
            board[i].push_back(x);
        }
    }

    d[0][0] = board[0][0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if(j==0) {
                d[i][j] = d[i-1][j] + board[i][j];
                continue;
            }
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + board[i][j];
//            cout << i << ' ' << j << ' ' << d[i][j] << '\n';
        }
    }

    cout << *max_element(d[n-1], d[n-1]+n);
}
