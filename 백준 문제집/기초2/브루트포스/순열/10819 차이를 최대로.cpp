#include <bits/stdc++.h>
using namespace std;
int n;
int a[9];
int mx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    while(next_permutation(a, a+n)) {
        int sum = 0;
        for(int i=0; i<n-1; i++) {
            sum += abs(a[i] - a[i+1]);
        }
        mx = max(mx, sum);
    }
    cout << mx << '\n';
}