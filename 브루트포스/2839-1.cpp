#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<=n/3; i++) {
        for(int j=0; j<=n/5; j++) {
//            cout << 3*i + 5*j << '\n';
            if(3*i + 5*j == n) {
                cout << i + j << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
}