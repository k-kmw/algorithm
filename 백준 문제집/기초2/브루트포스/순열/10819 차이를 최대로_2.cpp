#include <bits/stdc++.h>
using namespace std;
int n;
int a[9];
int p[9];
bool vis[9];
int mx;

void permutation(int k) {

    if(k == n) {
        int sum = 0;
        for(int i=0; i<n-1; i++) {
            sum += abs(p[i] - p[i+1]);
        }
        mx = max(mx, sum);
        return;
    }
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        p[k] = a[i];
        vis[i] = true;
        permutation(k+1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    permutation(0);
    cout << mx << '\n';
}