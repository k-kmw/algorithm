#include <bits/stdc++.h>
using namespace std;
int n;
int t[16];
int p[16];
int ans;

void dfs(int st, int sum) {
    if(st > n+1) { // st가 n+1보다 크면 범위를 벗어남
        return;
    }

    ans = max(ans, sum);
    for(int i=st; i<=n; i++) {
        dfs(i+t[i], sum + p[i]); // 다음 가능한 일자로 넘어감
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)  cin >> t[i] >> p[i];

    dfs(1, 0);
    cout << ans;
}