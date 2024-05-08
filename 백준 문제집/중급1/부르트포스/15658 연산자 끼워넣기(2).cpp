#include <bits/stdc++.h>
using namespace std;

int n;
int a[15];
int op[4];
int mx = -INT_MAX;
int mn = INT_MAX;

// k번째 연산자를 결정했을 때의 결과가 res
void dfs(int k, int res) {
    if(k == n-1) {
        mx = max(mx, res);
        mn = min(mn, res);
        return;
    }
    for(int i=0; i<4; i++) {
        if(op[i] == 0) continue;
        op[i]--;
        switch(i) {
            case 0:
                dfs(k+1, res+a[k+1]);
                break;
            case 1:
                dfs(k+1, res-a[k+1]);
                break;
            case 2:
                dfs(k+1, res*a[k+1]);
                break;
            case 3:
                dfs(k+1, res/a[k+1]);
                break;
        }
        op[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<4; i++) {
        cin >> op[i];
    }

    dfs(0, a[0]);

    cout << mx << '\n';
    cout << mn << '\n';
}