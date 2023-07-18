#include <bits/stdc++.h>
using namespace std;
int tot;
int n;
int ans = 5000;
int cnt;
int sugar[2] = {5, 3};
int count1;

void bag(int k) {
    count1++;
//    cout << tot << '\n';
    if(tot > n) return;
    if(tot == n) {
        ans = min(ans, cnt);
        return;
    }
    for(int i=0; i<2; i++) {
        tot += sugar[i];
        cnt++;
        bag(k+1);
        tot -= sugar[i];
        cnt--;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    bag(0);
    if(ans == 5000) {
        cout << -1;
    }
    else
        cout << ans;

    cout << '\n';
    cout << count1;
}

// 상한을 정하자면 대략 2^1666 (5000 / 3 ~= 1666)
// 시간 초과