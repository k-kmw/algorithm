#include <bits/stdc++.h>
using namespace std;
int t[16];
int p[16];
int d[8];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
        d[i] = 0;
    }
    d[1] = p[1];
    int pre;
    for(int i=1; i<=n; i++) {
        int cur = i;
        while(true) {
            pre = cur;
            cur += t[cur];
            if (cur > n || (cur + t[cur] > n)) break;
            d[i] = p[i];
//            cout << i << ' ' << cur << '\n';
            d[cur] = max(d[cur], d[pre] + p[cur]);
        }
    }
    cout << *max_element(d+1, d+1+n);
}
