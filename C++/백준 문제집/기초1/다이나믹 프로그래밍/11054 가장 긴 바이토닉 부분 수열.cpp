#include <bits/stdc++.h>
using namespace std;
int a[1001];
int d[1001];
int r_d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }

    for(int i=1; i<=n; i++) {
        d[i] = 1;
        for(int j=1; j<i; j++) {
            if(a[i] > a[j]) {
                d[i] = max(d[i], d[j]+1);
            }
        }
    }
    for(int i=n; i>=1; i--) {
        r_d[i] = 1;
        for(int j=n; j>i; j--) {
            if(a[i] > a[j]) {
                r_d[i] = max(r_d[i], r_d[j]+1);
            }
        }
    }
    int mx = 0;
    for(int i=1; i<=n; i++) {
        mx = max(mx, d[i] + r_d[i] - 1);
    }
    cout << mx << '\n';
}