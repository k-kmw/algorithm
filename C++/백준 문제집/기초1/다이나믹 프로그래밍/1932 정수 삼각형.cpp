#include <bits/stdc++.h>
using namespace std;
int a[501][501];
int d[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            cin >> a[i][j];
        }
    }

    d[0][0] = a[0][0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(j == 0) {
                d[i][j] = d[i-1][j] + a[i][j];
            }
            else if(j == n-1) {
                d[i][j] = d[i-1][j-1] + a[i][j];
            }
            else {
                d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j];
            }
        }
    }
    cout << *max_element(d[n-1], d[n-1]+n) << '\n';
}