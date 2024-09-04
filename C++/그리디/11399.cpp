#include <bits/stdc++.h>
using namespace std;
int p[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)  cin >> p[i];
    sort(p, p+n);

    int ans = 0;
//    int tmp = 0;
//    for(int i=0; i<n; i++) {
//        tmp += p[i];
//        ans += tmp;
//    }
    for(int i=0; i<n; i++) {
        ans += p[i] * (n-i); // p[i]가 (n-i)번 더해짐
    }
    cout << ans;
}

// 가장 짧은 시간을 먼저 선택
// 귀류법 가장 짧은 시간 먼저 선택하지 않음 -> 1 3 2 3 4 반례
// 지금 당장 이득을 보더라도 나중에 손해보는 경우가 있는지 확인