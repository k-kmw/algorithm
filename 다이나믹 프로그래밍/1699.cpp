#include <bits/stdc++.h>
using namespace std;
int d[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        d[i] = i;
        for(int j=1; j*j<=i; j++) {
            d[i] = min(d[i], d[i-j*j]+1);
        }
    }
    cout << d[n];
}

//풀이 보고 풀었음.
//다시 풀어보기