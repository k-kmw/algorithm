#include <bits/stdc++.h>
using namespace std;
int n;
int d[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 0;
    d[2] = 1;
    d[3] = 1;
    for(int i=4; i<=n; i++) {
        d[i] = d[i-1] + 1;
        if(i % 3 == 0) {
            d[i] = min(d[i], d[i/3] + 1);
        }
        if(i % 2 == 0) {
            d[i] = min(d[i], d[i/2] + 1);
        }
    }
    cout << d[n];
}