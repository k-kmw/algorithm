#include <bits/stdc++.h>
using namespace std;

int n;
char op[10];
bool vis[10];
string mx = "0";
string mn = "9876543210";
string tmp;

bool checkValid() {
    bool valid = true;
    for(int i=0; i<n; i++) {
        if(op[i] == '<') {
            if(tmp[i] > tmp[i+1]) {
                valid = false;
                break;
            }
        }
        else { // op: >
            if(tmp[i] < tmp[i+1]) {
                valid = false;
                break;
            }
        }
    }
    return valid;
}

void dfs(int k) {
    if(k == n+1) {
        if(checkValid()) {
            mx = max(mx, tmp);
            mn = min(mn, tmp);
        }
        return;
    }

    for(int i=0; i<=9; i++) {
        if(vis[i]) continue;
        tmp += to_string(i);
        vis[i] = true;
        dfs(k+1);
        tmp.pop_back();
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> op[i];
    dfs(0);
    cout << mx << '\n';
    cout << mn << '\n';
}