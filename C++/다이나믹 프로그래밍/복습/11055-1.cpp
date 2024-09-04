#include <bits/stdc++.h>
using namespace std;
int d[1001];
int a[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n; i++) {
        d[i] = a[i];
        for(int j=1; j<i; j++) {
            if(a[j] < a[i]) d[i] = max(d[i], d[j] + a[i]);
        }
    }
    cout << *max_element(d+1, d+1+n);
}

// check