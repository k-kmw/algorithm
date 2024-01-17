#include <bits/stdc++.h>
using namespace std;
int n;
int d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    for (int i = 1; i <= n; i++) {
        d[i] = i;
        for (int j = sqrt(i); j >= 2; j--) {
            int power = pow(j, 2);
            d[i] = min(d[i], d[i - power] + 1);
        }
    }
    cout << d[n];
}