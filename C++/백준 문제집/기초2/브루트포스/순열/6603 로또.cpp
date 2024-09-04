#include <bits/stdc++.h>
using namespace std;
int n = -1;
int a[14];
int p[14];
bool vis[14];

void dfs(int k, int st) {
    if(k == 6) {
        for(int i=0; i<6; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=st; i<n; i++) {
        if(vis[i]) continue;
        p[k] = a[i];
        vis[i] = true;
        dfs(k+1, i+1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    while(n != 0) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        dfs(0, 0);
        cout << '\n';
    }
}

// O(12P6)