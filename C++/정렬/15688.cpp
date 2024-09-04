#include <bits/stdc++.h>
using namespace std;

int freq[2000002];
const int HALF = 2000000 / 2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if(x <= 0) {
            x = abs(x);
            freq[x]++;
        }
        else
            freq[x + HALF]++;
    }

    for(int i=HALF; i>=0; i--) {
        if(freq[i] != 0) {
            freq[i]--;
            cout << -i << '\n';
            i++;
        }
    }

    for(int i=HALF+1; i<=2*HALF; i++) {
        if(freq[i] != 0) {
            freq[i]--;
            cout << i - HALF << '\n';
            i--;
        }
    }
}