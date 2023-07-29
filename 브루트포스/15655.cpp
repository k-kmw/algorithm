#include <bits/stdc++.h>
using namespace std;
bool vis[10000];
int arr[9];
int n, m;
vector<int> vec;

void dfs(int k, int st) {
    if(k == m) {
        for (const auto &v: vec) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=st; i<n; i++) {
        if(vis[arr[i]]) continue;
        vis[arr[i]] = true;
        vec.push_back(arr[i]);
        dfs(k+1, i+1);
        vis[arr[i]] = false;
        vec.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    dfs(0, 0);
}