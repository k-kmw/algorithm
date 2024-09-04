#include <bits/stdc++.h>
using namespace std;
int a[1001];
int d[1001]; // i번째 수열까지 증가하는 부분 수열의 합의 최대값

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    d[1] = a[1];
    for(int i=2; i<=n; i++) {
        d[i] = a[i];
        for(int j=1; j<i; j++) {
            if(a[j] < a[i]) {
                d[i] = max(d[i], d[j] + a[i]);
            }
        }
    }
    cout << *max_element(d+1, d+n+1) << '\n';
}