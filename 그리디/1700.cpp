#include <bits/stdc++.h>
using namespace std;
int items[101];
int cnt[101];
int holes[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    for(int i=1; i<=k; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        items[i] = x;
    }

    int ans = 0;
    for(int i=1; i<=k; i++) { // 아이템
        int min = cnt[1];
        int minIdx = 1;
        for(int j=1; j<=n; j++) { // 멀티탭
            if(min < cnt[j]) {
                min = cnt[j];
                minIdx = j;
            }
            if(holes[j] == 0 || holes[j] == items[i]) {
                holes[j] = items[i];
                break;
            }
            else if(j==n && (holes[j] != 0 || holes[j] != items[i])) {
                int idx = find(holes+1, holes+n+1, minIdx) - (holes+1);
                cout << minIdx << ' ' << idx << ' ' << holes[idx] << '\n';
                holes[idx] = items[i];
                ans++;
            }
        }
        cnt[items[i]]--;
    }
    cout << ans;
}