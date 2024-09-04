#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[21];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i=1; i<(1<<n); i++) {
        int sum = 0;
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) {
                sum += a[j];
            }
        }
        if(sum == s) {
//            cout << i << '\n';
            ans++;
        }
    }
    cout << ans << '\n';
}