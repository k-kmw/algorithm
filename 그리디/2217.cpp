#include <bits/stdc++.h>
using namespace std;
int w[100001];
int d[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> w[i];

    sort(w+1, w+n+1, greater<>());
//    for(int i=1; i<=n; i++) {
//        cout << w[i] << ' ';
//    }
    d[1] = w[1];
    for(int i=2; i<=n; i++) {
        d[i] = max(d[i-1], i*w[i]);
    }
    cout << d[n];
}
