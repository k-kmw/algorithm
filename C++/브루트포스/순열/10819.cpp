#include <bits/stdc++.h>
using namespace std;
int n;
int a[9];
bool vis[9];
vector<int> vec;
int ans;

int getDist() {
    int res = 0;
    for(int i=0; i<vec.size()-1; i++) {
        res += abs(vec[i] - vec[i+1]);
    }
//    cout << res << '\n';
    return res;
}

void dfs(int k) {
    if(k == n) {
        ans = max(ans, getDist());
    }
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        vec.push_back(a[i]);
        vis[i] = true;
        dfs(k+1);
        vec.pop_back();
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)  cin >> a[i];
    dfs(0);
    cout << ans;
}