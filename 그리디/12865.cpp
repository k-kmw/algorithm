#include <bits/stdc++.h>
using namespace std;
int w[101];
int v[101];
int d[101][100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> w[i] >> v[i];

    int mx = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j < w[i]) {
                d[i][j] = d[i-1][j];
            }
            else {
                d[i][j] = max(d[i-1][j], d[i-1][j-w[i]] + v[i]);
            }
            mx = max(mx, d[i][j]);
        }
    }

    cout << mx;
}
// 그리디로 풀 수 없는데, 잘못 풀 가능성이 있는 문제
// 무게 대비 가치가 높은 순으로 선택하는 그리디 풀이?
// dp로 풀이