#include <bits/stdc++.h>
using namespace std;
int s[100001];
int d[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> s[i];
        d[i] = s[i];
    }

    for(int i=1; i<=n; i++) {
        d[i] = max(d[i], d[i-1]+s[i]);
    }
    cout << *max_element(d+1, d+1+n);
}
