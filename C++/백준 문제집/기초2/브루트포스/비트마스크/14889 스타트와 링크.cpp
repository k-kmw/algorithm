#include <bits/stdc++.h>
using namespace std;

int n;
int s[21][21];
bool selected[21];
int mn = 10e8;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 스타트 팀의 능력치와 링크 팀의 능력치 차이를 최소로
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> s[i][j];
        }
    }

    for(int i=0; i<(1<<n); i++) { // 부분집합 구하기
        int cnt = 0;
        fill(selected, selected+n, false);
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) {
                cnt++;
                selected[j] = true;
            }
        }
        if(cnt == n/2) {
            int sum1 = 0;
            int sum2 = 0;
            for(int k=0; k<n; k++) {
                for(int l=0; l<n; l++) {
                    if(selected[k] && selected[l]) {
                        sum1 += s[k][l];
                    } else if(!selected[k] && !selected[l]) {
                        sum2 += s[k][l];
                    }
                }
            }
            mn = min(mn, abs(sum1 - sum2));
        }
    }
    cout << mn << '\n';
}