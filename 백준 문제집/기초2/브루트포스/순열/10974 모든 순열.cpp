#include <bits/stdc++.h>
using namespace std;
int n;
int a[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        a[i-1] = i;
    }
    do {
        for(int i=0; i<n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } while(next_permutation(a, a+n));
}