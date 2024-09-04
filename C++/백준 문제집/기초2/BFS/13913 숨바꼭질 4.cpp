#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
int p[100005];
vector<int> path;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(p, p+100005, -1);
    queue<pair<int, int>> q;
    q.push({n, 0});
    vis[n] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur.first == k) {
            int x = cur.first;
            ans = cur.second;
            while(x != -1) {
                path.push_back(x);
                x = p[x];
            }
            break;
        }
        for(int nx : {cur.first-1, cur.first+1, cur.first*2}) {
            if(nx < 0 || nx > 100000 || vis[nx]) continue;
            q.push({nx, cur.second+1});
            vis[nx] = true;
            p[nx] = cur.first;
        }
    }

    cout << ans << '\n';
    for(int i=path.size()-1; i>=0; i--) {
        cout << path[i] << ' ';
    }
}