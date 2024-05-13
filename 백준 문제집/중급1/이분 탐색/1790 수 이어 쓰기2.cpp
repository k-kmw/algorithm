#include <bits/stdc++.h>
using namespace std;

long long n, k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    long long unit = 9;
    long long coe = 1;
    while (true) {
        if (k - coe * unit > 0) {
            k -= coe * unit;
        }
        else {
            break;
        }
        coe++;
        unit = unit * 10;
    }
//    cout << coe << '\n';
//    cout << k << '\n';
    long long  share = (k-1) / coe;
//    cout << share << '\n';
    long long idx = (k-1) % coe;
    long long st = (long long) unit / 9;
    string num = to_string(st + share);
    if(stol(num) > n) {
        cout << -1 << '\n';
    } else {
        cout << num[idx] << '\n';
    }
//    cout << num << '\n';
}