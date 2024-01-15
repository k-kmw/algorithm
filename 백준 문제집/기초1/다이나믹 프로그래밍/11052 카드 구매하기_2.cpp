#include <bits/stdc++.h>
using namespace std;
int n;
int p[1001];
vector<int> vec;
int tmp;
int mx;

void dfs(int st) {
    if(tmp == n) {
        int sum = 0;
        for (const auto &v: vec) {
            sum += p[v];
        }
        mx = max(sum, mx);
        return;
    }
    if(tmp > n) {
        return;
    }
    for(int i=st; i<=n; i++) {
        tmp += i;
        vec.push_back(i);
        dfs(i);
        tmp -= i;
        vec.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> p[i];
    }
    dfs(1);
    cout << mx << '\n';
}

// 시간 초과