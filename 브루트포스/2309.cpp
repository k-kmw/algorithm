#include <bits/stdc++.h>
using namespace std;
int tall[10];
bool vis[10];
int tot;

void solve(int idx, int k) {
    if(k == 7) {
        if(tot == 100) {
            for(int i=0; i<9; i++) {
                if(vis[i]) {
                    cout << tall[i] << '\n';
                }
            }
            exit(0);
        }
        return;
    }

    for(int i=idx; i<9; i++) {
        if(!vis[i]) {
            vis[i] = true;
            tot += tall[i];
            solve(idx+1, k + 1);
            vis[i] = false;
            tot -= tall[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<9; i++)
        cin >> tall[i];
    sort(tall, tall+9);
    solve(0, 0);
}