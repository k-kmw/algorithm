#include <bits/stdc++.h>
using namespace std;

int a[100005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int st = 0, en = 0;
    int mn = 100005;
    int sum = 0;
    while (true) {
        //cout << st << ' ' << en << '\n';
        if (sum >= s) {
            mn = min(mn, en - st);
            sum -= a[st++];
        }
        else if (en == n) {
            break;
        }
        else {
            sum += a[en++];
        }
    }
    if (mn == 100005) {
        cout << 0 << '\n';
        return 0;
    }
    cout << mn << '\n';
}