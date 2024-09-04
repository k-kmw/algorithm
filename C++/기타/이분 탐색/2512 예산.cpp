#include <bits/stdc++.h>
using namespace std;

int n, m;
int budget[10005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> budget[i];
        sum += budget[i];
    }
    cin >> m;

    if(sum <= m) {
        cout << *max_element(budget, budget+n);
        return 0;
    }

    // 1 ~ m 이분 탐색을 통해 총액 이내로 최대의 예산을 만드는 상한액 구하기
    int st = 1;
    int en = m;
    int mx = 0;
    int maxUpper = 0;
    while(st <= en) {
        int upper = (st + en) / 2;
//        cout << upper << '\n';
        int tmp = 0;
        for(int i=0; i<n; i++) {
            if(budget[i] < upper) {
                tmp += budget[i];
            } else {
                tmp += upper;
            }
        }
        if(tmp <= m) {
            if(mx < tmp) {
                mx = tmp;
                maxUpper = upper;
            }
            st = upper + 1;
        } else {
            en = upper - 1;
        }
    }
    cout << maxUpper;
}