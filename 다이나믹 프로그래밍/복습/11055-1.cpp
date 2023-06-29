#include <bits/stdc++.h>
using namespace std;
int d[1001];
int a[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) cin >> a[i];
    int pre = a[1];
    d[1] = a[1];
    for(int i=2; i<=n; i++) {
        if(pre < a[i]) {
            d[i] = d[i-1] + a[i];
            pre = a[i];
            cout << d[i] << '\n';
        }
    }
    cout << d[n];
}
