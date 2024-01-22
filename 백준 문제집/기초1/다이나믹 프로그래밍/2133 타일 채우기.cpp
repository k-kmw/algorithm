#include <bits/stdc++.h>
using namespace std;
int d[31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    d[2] = 3;
    d[4] = 11;
    for(int i=5; i<=n; i++) {
        if(i % 2 != 0) {
            d[i] = 0;
        }
        else {
            d[i] = d[i-4] * d[i-2];
        }
    }
    cout << d[n] << '\n';
}
// 다시 풀기.