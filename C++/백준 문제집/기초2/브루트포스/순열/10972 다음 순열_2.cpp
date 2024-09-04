#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    if(next_permutation(a, a+n)) {
        for(int i=0; i<n; i++) {
            cout << a[i] << ' ';
        }
        return 0;
    }
    cout << -1 << '\n'
}