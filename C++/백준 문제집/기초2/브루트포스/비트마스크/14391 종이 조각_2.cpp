#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[5];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < (1 << (n * m)); i++) {

        int sum = 0;
        for(int k=0; k<n; k++) {
            int tmp = 0;
            for(int l=0; l<m; l++) {
                int pos = k*m + l;
                if((i & (1<<pos)) == 0) {
                    tmp = tmp*10 + board[k][l] - '0';
                } else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }

        for(int k=0; k<m; k++) {
            int tmp = 0;
            for(int l=0; l<n; l++) {
                int pos = l*m + k;
                if((i & (1<<pos)) != 0) {
                    tmp = tmp*10 + board[l][k] - '0';
                } else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}