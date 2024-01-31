#include <bits/stdc++.h>
using namespace std;
int tmp;
int ans;
int n;

void dfs() {
    if (tmp > n) {
        return;
    }

    if (tmp == n) {
        ans++;
    }

    for (int i = 1; i <= 3; i++) {
        tmp += i;
        dfs();
        tmp -= i;
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        dfs();
        cout << ans << '\n';
    }
}