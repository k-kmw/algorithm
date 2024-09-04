#include <bits/stdc++.h>
using namespace std;
int a[1001];
int d[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n; i++) {
        d[i] = a[i];
        for(int j=0; j<i; j++) {
            if(a[j] < a[i]) d[i] = max(d[i], d[j] + a[i]);
        }
    }
    cout << *max_element(d, d+n);
}

//못풀어서 답지 보고 풀이