#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        int x, y;
        cin >> m >> n >> x >> y;
        int year = 0;
        int nx = 0;
        int ny = 0;
        while(1) {
            if(nx == m+1) {
                nx = 1;
            }
            if(ny == n+1) {
                ny = 1;
            }
            if(nx == x && ny == y) {
                cout << year << '\n';
                break;
            }
            else if(year >= m*n) {
                cout << -1 << '\n';
                break;
            }
            nx++;
            ny++;
            year++;
        }
    }

}