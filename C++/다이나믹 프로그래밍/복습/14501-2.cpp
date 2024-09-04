#include <bits/stdc++.h>
using namespace std;
int d[16];
int t[16];
int p[16];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
        if(i+t[i]<=n)
            d[i] = p[i];
    }

    for(int i=1; i<=n; i++) {
        int nxt = i + t[i];
        int pre = i;
        while(nxt <= n) {
            cout << nxt << ' ';
            if(nxt + t[nxt] <= n+1) {
                d[nxt] = max(d[nxt], d[pre] + p[nxt]);
            }
            pre = nxt;
            nxt += t[nxt];
        }
        cout << d[i] << '\n';
    }
//    cout << *max_element(d+1, d+n+1);
}
