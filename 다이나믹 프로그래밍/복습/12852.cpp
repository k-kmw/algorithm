#include <bits/stdc++.h>
using namespace std;
int d[1000001];
int a[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    d[1] = 0;
    a[1] = 0;
    for(int i=2; i<=n; i++) {
        d[i] = d[i-1]+1;
        a[i] = i-1;
        if(i%3 == 0) {
            if(d[i] > d[i/3]+1) {
                d[i] = d[i/3] + 1;
                a[i] = i/3;
            }
        }
        if(i%2 == 0) {
            if(d[i] > d[i/2]+1) {
                d[i] = d[i/2] + 1;
                a[i] = i/2;
            }
        }
    }
//    int idx = n;
//    cout << n << ' ';
//    while(a[idx] >= 1) {
//        cout << a[idx] << ' ';
//        idx = a[idx];
//    }

    cout << d[n] << '\n';
    int cur = n;
    while(cur >= 1) {
        cout << cur << ' ';
        cur = a[cur];
    }
}