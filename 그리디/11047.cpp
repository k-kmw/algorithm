#include <bits/stdc++.h>
using namespace std;
int coin[11];
int cnt;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> coin[i];

    int bal = k;
    for(int i=n-1; i>=0; i--) {
        while(bal >= coin[i]) {
            bal -= coin[i];
            cnt++;
        }
    }
    cout << cnt;
}