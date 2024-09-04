#include <bits/stdc++.h>
using namespace std;
int n;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int series = 666;
    int cnt = 0;
    while(true) {
        int tmp = series;
        while(tmp >= 666) {
            if(tmp % 1000 == 666) {
                cnt++;
                break;
            }
            tmp /= 10;
        }
        if(n == cnt) {
            cout << series << '\n';
            break;
        }
        series++;
    }
}