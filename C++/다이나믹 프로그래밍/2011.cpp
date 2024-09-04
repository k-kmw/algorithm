#include <bits/stdc++.h>
using namespace std;
string s;
int a[5001];
int dp[5001]; // dp[i] = i번째 문자까지 읽었을 때 나올 수 있는 해석의 개수
int mod = 1000000;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    unsigned int n = s.length();
    for(int i=1; i<=n; i++) {
        a[i] = s[i-1] - '0'; // 문자열을 숫자로 변환
    }
    dp[0] = 1; // 초기값 설정
    for(int i=1; i<=n; i++) { // 점화식
        if(a[i] > 0) { // 0인 경우 예외가 발생하므로 0보다 큰 경우
            dp[i] = (dp[i] + dp[i-1])%mod; // 0보다 큰 경우 이전의 경우의 수와 같음. 이전 문자열에 문자 하나만 추가하기 때문
        }
        int x = a[i-1]*10 + a[i];
        if(x >= 10 && x <= 26) { // 앞 숫자와 뒤의 숫자로 구한 수가 해당 범위이면
            dp[i] = (dp[i]+dp[i-2])%mod; // 2자리 수이므로 2칸 전의 경우의수에 2자리에 해당하는 문자를 추가하는 경우까지 더해줘야 함
        }
    }

    cout << dp[n];
}
