#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> w;
int ans;

void dfs(vector<int> const& tmp, int energy) {
    if(tmp.size() == 2) {
        ans = max(ans, energy);
        return;
    }

    for(int i=1; i<tmp.size()-1; i++) {
        vector<int> tmp2(tmp);
        int e = tmp2[i-1]*tmp2[i+1];
        tmp2.erase(tmp2.begin()+i);
        dfs(tmp2, energy + e);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        w.push_back(x);
    }
    dfs(w, 0);
    cout << ans << '\n';
}