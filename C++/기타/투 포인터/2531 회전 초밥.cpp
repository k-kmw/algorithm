#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int a[30005];
int fishNum[3005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int st = 0;
    int en = k-1;

    int cnt = 0;

    for(int i=st; i<=en; i++) {
        fishNum[a[i]]++;
        if(fishNum[a[i]] == 1) {
            cnt++;
        }
    }

    fishNum[c]++;
    if(fishNum[c] == 1) cnt++;

//    cout << cnt << '\n';

    int mx = cnt;

    while(1) {

        fishNum[a[st]]--;
        if(fishNum[a[st]] == 0) cnt--;
        st++;

        en++;
        if(en == n) {
            en = 0;
        }
        fishNum[a[en]]++;
        if(fishNum[a[en]] == 1) cnt++;

//        cout << st << ' ' << en << ' ';
//        cout << mx << '\n';

        mx = max(mx, cnt);

        if(st == n-1) break;
    }
    cout << mx << '\n';
}

