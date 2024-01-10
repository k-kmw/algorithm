#include <bits/stdc++.h>

using namespace std;
int arr[9];
int arr2[9];
int n, m;

void dfs(int k, int st) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr2[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    for(int i=st; i<n; i++) {
        if(tmp != arr[i]) {
            arr2[k] = arr[i];
            tmp = arr2[k];
            dfs(k+1, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0, 0);
}