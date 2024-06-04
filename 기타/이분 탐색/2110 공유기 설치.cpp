#include <bits/stdc++.h>
using namespace std;

int n, c;
int home[200005];
int ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for(int i=0; i<n; i++) {
        cin >> home[i];
    }

    sort(home, home+n);
    int l = 1;
    int r = home[n-1] - home[0]; // 최대 거리를 이분 탐색을 통해 구하기
    while(l <= r) {
        int len = (l + r) / 2;

        int cnt = 1;
        int cur = home[0]; // 조건을 만족하는지만 검사하면 되기 떄문에 가장 유리하게 첫 번째 집에 공유기를 설치
        for(int i=1; i<n; i++) { // 이분 탐색으로 찾은 거리가 조건을 만족할 수 있는지 확인
            if(home[i] - cur >= len) { // 이분 탐색으로 찾은 거리가 가장 인접한 두 공유기 사이 거리이므로 이렇게 확인
                cnt++;
                cur = home[i];
            }
            if(cnt >= c) {
                break;
            }
        }
        if(cnt >= c) { // 만약 공유기를 모두 설치할 수 있으면, 최대값을 갱신하고 더 큰 값으로 시도하기
            l = len + 1;
            ans = max(ans, len);
        } else { // 공유기를 모두 설치할 수 없으면, 값을 낮추기
            r = len - 1;
        }
    }
    cout << ans;
}