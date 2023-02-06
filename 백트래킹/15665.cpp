#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[20];
int ans[20];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++)
            cout << ans[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    int tmp = 0;
    for(int i=0; i<n; i++) {
        if(tmp != ans[i]) { // 동일 자리의 이전 원소와 같지 않을 경우
            arr[k] = i;
            tmp = ans[i];
            func(k+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> ans[i];
    sort(ans, ans+n); // 오름차순 정렬
    func(0);
}
