#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[20];
int ans[20];
bool isused[20];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) {
            cout << ans[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    int st = 0;
    if(k != 0)   st = arr[k-1]+1;
    for(int i=st; i<n; i++) {
        if(!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k+1);
            isused[i] = false;
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
    func(0);
}