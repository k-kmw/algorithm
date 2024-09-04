#include <bits/stdc++.h>
using namespace std;
int d[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    d[1] = 1;
    d[2] = 3;
    int n;
    cin >> n;
    for(int i=3; i<=n; i++) {
        d[i] = (d[i-1] + 2*d[i-2])%10007;
    }
    cout << d[n];
}
