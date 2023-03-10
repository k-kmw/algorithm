#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[20];
int ans[20];

void func(int k, int st) {
    if(k == m) {
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int tmp = 0;
    for(int i=st; i<n; i++) {
        if(tmp != ans[i]) {
            arr[k] = ans[i];
            tmp = arr[k];
            func(k+1, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> ans[i];
    sort(ans, ans+n);
    func(0, 0);
}

