#include <bits/stdc++.h>
using namespace std;
int n;
int s[21][21];
bool vis[21];
int mn = 100*10+1;

void comb(int k, int st) {

    if(k == n/2) {
        int t1 = 0;
        int t2 = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(vis[i] && vis[j]) {
                    t1 += s[i][j];
                }
                else if(!vis[i] && !vis[j]){
                    t2 += s[i][j];
                }
            }
        }
        mn = min(mn, abs(t1-t2));
        return;
    }
    for(int i=st; i<n; i++) {
        vis[i] = true;
        comb(k+1, i+1);
        vis[i] = false;
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> s[i][j];
        }
    }
    comb(0, 0);
    cout << mn << '\n';
}