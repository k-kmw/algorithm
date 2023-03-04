#include <bits/stdc++.h>
using namespace std;
int t[1500001];
int p[1500001];
int d[1500001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
    }

    for(int i=n; i>=1; i--) {
        if(i+t[i] <= n+1) {
            d[i] = max(d[i+1], d[i+t[i]]+p[i]);
        }
        else
            d[i] = d[i+1];
    }
    cout << *max_element(d+1, d+1+n);
}