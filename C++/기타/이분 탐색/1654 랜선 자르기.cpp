#include <bits/stdc++.h>
using namespace std;

int k, n;
int lan[10005];
long long ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for(int i=0; i<k; i++) {
        cin >> lan[i];
    }
    long long l = 1;
    long long r = *max_element(lan, lan+k);
    while(l <= r) {
        long long mid = (l + r) / 2;

//        cout << mid << '\n';
        int cnt = 0;
        for(int i=0; i<k; i++) {
            cnt += lan[i] / mid;
        }

        if(cnt >= n) {
            l = mid + 1;
            ans = max(ans, mid);
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}