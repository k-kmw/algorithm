#include <bits/stdc++.h>
using namespace std;
int a[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    d[n] = 1;
    for(int i=n-1; i>=1; i--) {
        for(int j=i+1; j<=n; j++) {
            if(a[i] < a[j]) {
                d[i] = max(d[i], d[j]);
            }
        }
        d[i] = d[i] + 1;
    }
    cout << *max_element(d+1, d+n+1) << '\n';
}