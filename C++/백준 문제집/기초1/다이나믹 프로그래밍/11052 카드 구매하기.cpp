#include <bits/stdc++.h>
using namespace std;
int p[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> p[i];
    }
    d[1] = p[1];
    for(int i=2; i<=n; i++) {
        d[i] = p[i];
        for(int j=1; j<i; j++) {
            d[i] = max(d[i], d[i-j] + d[j]);
        }
    }
    cout << d[n] << '\n';
}