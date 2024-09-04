#include <bits/stdc++.h>
using namespace std;
int d[12];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i=4; i<11; i++) {
        d[i] = d[i-3] + d[i-2] + d[i-1];
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}

//n을 입력받을때마다 테이블을 계산하는 것보다 미리 구해두는 것이 더 효율적