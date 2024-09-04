#include <bits/stdc++.h>
using namespace std;

int n, m;
int lecture[100005];
int ans = INT_MAX;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> lecture[i];
        sum += lecture[i];
    }

    int st = *max_element(lecture, lecture+n);
    int en = sum;
    while(st <= en) {
        int mid = (st + en) / 2;

        int rec = 0;
        int cnt = 1;
        for(int i=0; i<n; i++) {
            rec += lecture[i];
            if(rec > mid) {
                rec = 0;
                i--;
                cnt++;
            }
            if(cnt > m) {
                break;
            }
        }
        if(cnt > m) {
            st = mid + 1;
        } else {
            en = mid - 1;
            ans = min(ans, mid);
        }
    }
    cout << ans;
}