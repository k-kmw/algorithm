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

    for(int i=0; i<n; i++) {
        arr[k] = i;
        func(k+1);
    }
}

vector<bool> chk(10002);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int idx = 0; // 중복 제거 하고 들어 있는 배열의 마지막 원소 인덱스(길이)
    for(int i=0; i<n; i++) {
        cin >> ans[idx];
        if(chk[ans[idx]]) continue; // 동일한 숫자가 나오면 idx가 증가 되지 않아 그 위에 덮어 씀
        chk[ans[idx]] = true;
        idx++;
    }
    n = idx;
    sort(ans, ans+n); // 오름 차순 정렬
    func(0);
}
