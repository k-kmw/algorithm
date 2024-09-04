#include <bits/stdc++.h>
using namespace std;
int n;
int a[10];
bool vis[10];

void permutation(int k) {
    if(k == n) {
        for (int i=0; i<n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    for(int i=1; i<=n; i++) {
        if (vis[i]) continue;
        a[k] = i;
        vis[i] = true;
        permutation(k+1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    permutation(0);
}