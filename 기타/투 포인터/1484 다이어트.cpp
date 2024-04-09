#include <bits/stdc++.h>
using namespace std;

bool isPossible;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s = 1;
    int e = 1;
    int g;
    cin >> g;
    while (true) {
        if (e * e - s * s <= g) {
            e++;
        }
        else {
            s++;
        }
        if (e == s) {
            break;
        }
        if (e * e - s * s == g) {
            isPossible = true;
            cout << e << '\n';
        }
    }
    if (!isPossible) {
        cout << -1 << '\n';
    }
}