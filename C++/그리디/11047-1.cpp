#include <bits/stdc++.h>
using namespace std;
int coin[11];
int cnt;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> coin[i];

    for(int i=n-1; i>=0; i--){
        cnt += k / coin[i];
        k %= coin[i];
    }
    cout << cnt;
}

// 주어진 동전들 사이 배수관계가 성립하기 때문에 그리디 알고리즘으로 풀이가능
// 아닐 경우 반례 ex)1원, 9원, 10원으로 18원 만들기 => 9원 2개 쓰는 것이 가장 좋은 경우
// 그리디 알고리즘은 문제 조건이 조금만 달라져도 풀이가 안될 수 있으므로, 비슷한 문제라고 똑같이 접근하면 안됨