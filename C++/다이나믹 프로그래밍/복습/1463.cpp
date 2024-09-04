#include <bits/stdc++.h>
using namespace std;
int d[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    d[1] = 0;
    d[2] = 1;
    d[3] = 1;
    for(int i=4; i<=n; i++) {
        if(i%6 == 0) {
            d[i] = min({d[i/3]+1, d[i/2] +1, d[i-1]+1});
        }
        else if(i%3 == 0) {
            d[i] = min(d[i/3]+1, d[i-1]+1);
        }
        else if(i%2 == 0) {
            d[i] = min(d[i/2]+1, d[i-1]+1);
        }
        else
            d[i] = d[i-1]+1;
    }
    cout << d[n];
}