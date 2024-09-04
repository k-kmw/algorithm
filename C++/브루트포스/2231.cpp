#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        int tmp = i;
        int ans = tmp;
        while(tmp > 0) {
            ans += tmp%10;
            tmp /= 10;
        }
        if(ans == n) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
}