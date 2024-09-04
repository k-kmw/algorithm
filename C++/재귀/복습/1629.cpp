#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 수의 범위가 크므로
ll func(ll a, ll n, ll m) {
    if(n == 1)    return a%m; // 종료 조건
    ll val = func(a, n/2, m); // a^n/2 구함
    val = val*val%m; // a^n 구함
    if(n%2 == 1) // 홀수일 경우
        val = val*a%m; // 한 번 더 계산 해줌
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c);
}
