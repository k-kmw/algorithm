#include <bits/stdc++.h>
using namespace std;
int s[301];
int d[301]; //i번째 계단까지 올라섰을 때 밟지 않을 계단의 합의 최솟값, i번째 계단은 반드시 밟지 않을 계단으로 선택해야 함

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int tot = 0;
    for(int i=1; i<=n; i++)  {
        cin >> s[i];
        tot += s[i];
    }
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    for(int i=4; i<n; i++) {
        d[i] = min(d[i-3], d[i-2]) + s[i];
    }
    cout << tot - min(d[n-1], d[n-2]);

}
