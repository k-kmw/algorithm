#include <bits/stdc++.h>
using namespace std;

int n, m;
int price[100005];
int ans = INT_MAX;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> price[i];
        sum += price[i];
    }

    int l = *max_element(price, price+n);
    int r = sum;
    while(l <= r) {
        int mid = (l + r) / 2;
//        cout << mid << '\n';
        int use = 0;
        int cnt = 1;
        for(int i=0; i<n; i++) {
            if(use + price[i] > mid) {
                cnt++;
                use = 0;
            }
            if(cnt > m) {
                break;
            }
            use += price[i];
        }
        if(cnt > m) {
            l = mid + 1;
        } else {
            ans = min(ans, mid);
            r = mid - 1;
        }
    }
    cout << ans;
}