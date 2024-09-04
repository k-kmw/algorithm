#include <bits/stdc++.h>
using namespace std;
int arr[9];
vector<int> arr2;
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
        vec.push_back(arr2[i]);
        dfs(k+1, i);
        vec.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    set<int> s(arr, arr+n);
    for (const auto &item: s) {
        arr2.push_back(item);
    }
    n = arr2.size();
    sort(arr2.begin(), arr2.end());
    dfs(0, 0);
}