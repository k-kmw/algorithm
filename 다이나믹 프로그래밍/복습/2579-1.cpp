#include <bits/stdc++.h>
using namespace std;
int s[301];
int d[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    for(int i=1; i<=n; i++) {
        cin >> s[i];
        sum += s[i];
    }
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    for(int i=4; i<n; i++) {
        d[i] = min(d[i-2], d[i-3]) + s[i];
    }
    d[n] = min(d[n-1], d[n-2]);
    cout << sum - d[n];
}