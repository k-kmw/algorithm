#include <bits/stdc++.h>
using namespace std;
int s[301];
int d[301][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> s[i];
    }
    if(n==1) {
        cout << s[1];
        return 0;
    }
    d[1][0] = s[1];
    d[1][1] = 0;
    d[2][0] = s[2];
    d[2][1] = s[1] + s[2];
    for(int i=3; i<=n; i++) {
        d[i][0] = max(d[i-2][0], d[i-2][1]) + s[i];
        d[i][1] = d[i-1][0] + s[i];
    }
    cout << max(d[n][0], d[n][1]);
}