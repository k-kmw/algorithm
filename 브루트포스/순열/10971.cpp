#include <bits/stdc++.h>
using namespace std;
int n;
int w[11][11];
bool vis[11];
int ans = 1000000*10 + 1;
vector<int> city;

int getWeight() {
    int res = 0;
    int prev = city[0];
    int cur;
    for(int i=1; i<city.size(); i++) {
        cur = city[i];
        if(w[prev][cur] == 0) {
            res += 1000000*10 + 1;
            return res;
        }
        else {
            res += w[prev][cur];
        }
        prev = cur;
    }
    int last = city[city.size()-1];
    if(w[last][city[0]] == 0) {
        res += 1000000*10 + 1;
    }
    else {
        res += w[last][city[0]];
    }
    return res;
}

void dfs(int k) {
    if(k == n) {
        ans = min(ans, getWeight());
        return;
    }
    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        city.push_back(i);
        vis[i] = true;
        dfs(k+1);
        city.pop_back();
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> w[i][j];
        }
    }
    dfs(0);
    cout << ans << '\n';
}