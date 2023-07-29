#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[10001];
int arr[10001];
int sortedArr[10001];
vector<int> vec;
bool flag;

void dfs(int k) {
    for(int i=0; i<vec.size(); i++) {
        if(arr[i] != vec[i] && !flag)
            return;
    }

    if(k == n) {
        if(flag) {
            for (const auto &v: vec) {
                cout << v << ' ';
            }
            exit(0);
        }
        flag = true;
        return;
    }

    for(int i=0; i<n; i++) {
        if(vis[sortedArr[i]]) continue;
        vis[sortedArr[i]] = true;
        vec.push_back(sortedArr[i]);
        dfs(k+1);
        vis[sortedArr[i]] = false;
        vec.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        sortedArr[i] = arr[i];
    }
    sort(sortedArr, sortedArr+n);
    dfs(0);
    cout << -1;
}