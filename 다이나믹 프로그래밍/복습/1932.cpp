#include <bits/stdc++.h>
using namespace std;
int d[501][501];
int a[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cin >> a[i][j];
        }
    }
    d[1][1] = a[1][1];
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(j==1) {
                d[i][j] = d[i-1][j] + a[i][j];
            }
            else if(j==i) {
                d[i][j] = d[i-1][j-1] + a[i][j];
            }
            else {
                d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j];
            }
        }
    }
    cout << *max_element(d[n]+1, d[n]+n+1);
}