#include <bits/stdc++.h>
using namespace std;
int w[100001];
int d[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> w[i];

    sort(w+1, w+n+1, greater<>()); // 내림차순 정렬
    int ans = 0;
    for(int i=1; i<=n; i++) { // i는 선택한 로프 개수
        ans = max(ans, w[i]*i); // 오름차순 정렬임을 생각하고 누적된 최대 중량의 ans와 i번째 로프 무게*i와 비교하여 최대값 선택
    }
    cout << ans;
}
