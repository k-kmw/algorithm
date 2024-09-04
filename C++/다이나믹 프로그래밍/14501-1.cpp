#include <bits/stdc++.h>
using namespace std;
int t[16];
int p[16];
int d[16]; // i번째 일에 상담을 했을 때 얻을 수 있는 최대 수익

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
        d[i] = p[i]; //초기값을 i번째 날짜의 금액으로 초기화
    }

    for(int i=2; i<=n; i++) { //첫번째 날은 p[0]이므로 두번째 날부터 시작
        for(int j=1; j<i; j++) { //이전의 날들의 최대 비용에 현재 비용을 더한 것과 현재까지 저장된 최대 비용을 비교후 큰 값을 취함
            if(i-j >= t[j]) //i 이전의 값들을 순회할 때 일수의 차이가 t[j]보다 클 경우만 가능함
                d[i] = max(d[i], d[j] + p[i]);
        }
    }
//    for(int i=1; i<=n; i++) {
//        cout << d[i] << ' ';
//    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(i + t[i] <= n+1) { //일수가 퇴사일에 넘어가는 경우 제외
            ans = max(ans, d[i]);
        }
    }
    cout << ans;
}
//순서대로 풀이할 경우
//복습하기