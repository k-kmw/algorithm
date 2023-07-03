#include <bits/stdc++.h>
using namespace std;
int t[16];
int p[16];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> t[i] >> p[i];

    int mx = 0;
    for(int i=1; i<=n; i++) {
        int tmp = p[i];
        int nxt = i + t[i];
        for(int j=nxt; j<=n+1; j++) {
            if(j+p[j] >= n+1) {
                continue;
            }
            else {
                tmp +=
            }
        }
    }
}