#include <bits/stdc++.h>
using namespace std;
int n;
int tmp;
int cnt;

void dfs() {
    if(tmp > n) {
        return;
    }

    if(tmp == n) {
        cnt++;
        return;
    }
    for(int i=1; i<=3; i++) {
        tmp += i;
        dfs();
        tmp -= i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cnt = 0;
        dfs();
        cout << cnt << '\n';
    }
}