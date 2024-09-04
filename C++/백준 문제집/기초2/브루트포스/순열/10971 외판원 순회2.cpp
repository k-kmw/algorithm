#include <bits/stdc++.h>
using namespace std;
int n;
int w[11][11];
int a[11];
bool vis[11];
int mn = 1000000*10 + 1;

void perm(int k) {

    if(k == n) {
        int sum = 0;
        for(int i=0; i<n-1; i++) {
            if(w[a[i]][a[i+1]] == 0) {
                sum += 1000000*10 + 1;
                break;
            }
            sum += w[a[i]][a[i+1]];
        }
        if(w[a[n-1]][a[0]] == 0) {
            sum += 1000000*10 + 1;
        } else {
            sum += w[a[n-1]][a[0]];
        }
        mn = min(mn, sum);
        return;
    }

    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        a[k] = i;
        vis[i] = true;
        perm(k+1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> w[i][j];
        }
    }
    perm(0);
    cout << mn << '\n';
}