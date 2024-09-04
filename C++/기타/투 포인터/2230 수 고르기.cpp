#include <bits/stdc++.h>
using namespace std;

int a[100005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int s = 0, e = 1;
    int mn = 2000000001;
    while (true) {
        // cout << s << ' ' << e << '\n';
        int sub = a[e] - a[s];

        if (sub >= m) {
            mn = min(mn, sub);
            s++;
        }
        else if (e == n-1) {
            break;
        }
        else {
            e++;
        }
    }
    cout << mn << '\n';
}