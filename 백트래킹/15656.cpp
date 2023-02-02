#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[20];
int ans[20];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) {
            cout << ans[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++) {
        arr[k] = i;
        func(k+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> ans[i];
    sort(ans, ans+n);
    func(0);
}