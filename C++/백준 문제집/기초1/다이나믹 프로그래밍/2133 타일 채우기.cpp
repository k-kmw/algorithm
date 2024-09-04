#include <bits/stdc++.h>
using namespace std;
int d[31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    d[2] = 3;
    for(int i=4; i<=n; i++) {
        if(i % 2 != 0) {
            d[i] = 0;
        }
        else {
            d[i] = d[2] * d[i-2];
            for(int j=i-4; j>=2; j-=2) {
                d[i] += d[j] * 2;
            }
            d[i] += 2;
        }
    }
    cout << d[n] << '\n';
}
// 풀이 보고 품..