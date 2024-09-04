#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int a[30005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int st = 0;
    set<int> s;
    for(int i=0; i<k; i++) {
        s.insert(a[i]);
    }
    s.insert(c);
    int mx = s.size();

    while(1) {
        if(st == n-1) {
            break;
        }
        s.erase(a[st]);
        st++;
        int idx = st;
        for(int i=0; i<k; i++) {
            s.insert(a[idx]);
            idx++;
            if(idx == n) {
                idx = 0;
            }
        }
        s.insert(c);
        mx = max(mx, (int)s.size());
    }
    cout << mx << '\n';
}
// set의 insert 연산은 O(logN) => N*K*logN ~= 6*10^3*10^4 = 1.8*10^9