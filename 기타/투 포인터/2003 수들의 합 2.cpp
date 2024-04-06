#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int s = 0, e = 0;
    int sum = 0;
    int ans = 0;
    while(1) {
        if(sum >= m) {
            sum -= a[s++];
        }  else if(e == n){
            break;
        } else {
            sum += a[e++];
        }
        if(sum == m)    ans++;
    }
    cout << ans << '\n';
}