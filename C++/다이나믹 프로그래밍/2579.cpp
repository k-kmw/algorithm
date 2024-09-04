#include <bits/stdc++.h>
using namespace std;
int s[301];
int d[301][3]; //현재까지 j번째 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 접수합의 최댓값을 저장

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)  cin >> s[i];
    if(n == 1) { //n=1일 때, s[2]를 참조하지 않도록. d[2][1], d[2][2]
        cout << s[1];
        return 0;
    }
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = s[1] + s[2];

    for(int i=3; i<=n; i++) {
        d[i][1] = max(d[i-2][1], d[i-2][2]) + s[i];
        d[i][2] = d[i-1][1] + s[i];
    }
    cout << max(d[n][1], d[n][2]);
}
