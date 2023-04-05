#include <bits/stdc++.h>
using namespace std;
int p[1000001];
int n;
long long ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        fill(p, p+n, 0);
        for(int i=0; i<n; i++)
            cin >> p[i];

        int mx = p[n-1];
        for(int i=n-2; i>=0; i--) {
            if(mx < p[i])   mx = p[i];
            ans += mx - p[i];
        }

        cout << ans << '\n';
    }
}

// 앞에서부터 주식의 최대값에 판매하는 방식보다 뒤에서부터 확인하여 p[i]가 max보다 크면 max를 갱신 아니면, ans를 업데이트(주식을 판다)
