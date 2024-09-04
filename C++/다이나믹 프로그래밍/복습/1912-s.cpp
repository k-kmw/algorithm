#include <bits/stdc++.h>
using namespace std;
int d[100001];
int a[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++) {
        d[i] = max(a[i], d[i-1]+a[i]);
    }
    cout << *max_element(d+1, d+n+1);
}

// check