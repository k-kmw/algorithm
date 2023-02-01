#include <bits/stdc++.h>
using namespace std;

void star(int row, int col, int n) {
    if((row/n)%3 == 1 && (col/n)%3 == 1)    cout << ' ';
    if(n == 1)    cout << '*';
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int unit = n/3;
            star(row+i*unit, col+i*unit, unit);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            star(i, j, n);
        }
        cout << '\n';
    }
}
