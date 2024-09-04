#include <bits/stdc++.h>
using namespace std;

int getGcd(int m, int n) {
    int g = m > n ? m : n;
    int l = m > n ? n : m;
    int res;
    for(int i=1; i<=l; i++) {
        if(g%i == 0 && l%i == 0) {
            res = i;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        int x, y;
        cin >> m >> n >> x >> y;
//        x -= 1;
//        y -= 1;
        bool isEnd = false;
        int gcd = getGcd(m, n);
        for(int i=x; i<=m*n; i+=m) {
            if(i % n == y) {
                isEnd = true;
                cout << i << '\n';
                break;
            }
        }
        if(!isEnd)
            cout << -1 << '\n';
    }
}
// 못풀겠다 카잉달력