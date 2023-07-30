#include <bits/stdc++.h>
using namespace std;
int n;
int w[11][11];
int a[11];
int ans = 1000000*10 + 1;

int getWeight() {
    int res = 0;
    int prev = a[1];
    int cur;
    for(int i=2; i<=n; i++) {
        cur = a[i];
        if(w[prev][cur] == 0) {
            res += 1000000*10 + 1;
        }
        else {
            res += w[prev][cur];
        }
        prev = cur;
    }
    int last = a[n];
    if(w[last][a[1]] == 0) {
        res += 1000000*10 + 1;
    }
    else {
        res += w[last][a[1]];
    }
//    cout << res << '\n';
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> w[i][j];
        }
        a[i] = i;
    }
    do {
        ans = min(ans, getWeight());
    }
    while(next_permutation(a+1, a+n+1));
    cout << ans << '\n';
}