#include <bits/stdc++.h>
using namespace std;
int d[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    int pre = 1;
    int nxt;
    int power;
    for(int i=4; i<=n; i++) {
        if(sqrt(i) - (int)(sqrt(i)) == 0) {
            pre = power;
            power = i;
            d[power] = 1;
            nxt = ((int)(sqrt(i))+1) * ((int)(sqrt(i))+1);
        }
        else if(i < nxt-2) {
            d[i] = d[i-(power-pre)+1];
            cout << i << ' ' << d[i] << '\n';
        }
        else {
            d[i] = d[i % power] + 1;
        }
    }

    for(int i=1; i<=n; i++) {
        cout << d[i] << ' ';
    }

    cout << d[n];
}