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
    int tmp = 0;
    for(int i=0; i<n; i++) {
        if(!isused[i] && tmp != ans[i]) { // tmp가 새로 갱신된 i번째 숫자와 같으면 중복임
            arr[k] = i;
            isused[i] = true;
            tmp = ans[i]; // 이전 값인 i번째 숫자를 저장
            func(k+1);
            isused[i] = false;
        }
    }
    //각 계층마다 for문을 i=0 ~ i=n-1까지 돈다. tmp는 같은 계층에서 이전 인덱스에 저장되어 있는 원소 값
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

// 답지 보고 풀이