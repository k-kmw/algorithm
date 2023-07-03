#include <bits/stdc++.h>
using namespace std;
long long d[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    for(int i=5; i<=100; i++) {
        d[i] = d[i-1] + d[i-5];
    }

    while(t--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}
