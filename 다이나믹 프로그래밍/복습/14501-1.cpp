#include <bits/stdc++.h>
using namespace std;
int t[16];
int p[16];
int mx;
int tmp;
int n;

void dfs(int cur) {
    if(cur == n+1) {
        mx = max(mx, tmp);
        return;
    }
    for(int i=cur; i<=n; i++) {
        if(i + t[i] <= n+1) {
            tmp += p[i];
            dfs(i+t[i]);
            tmp -= p[i];
        }
        else {
            mx = max(mx, tmp);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
    }
    dfs(1);
    cout << mx;
}