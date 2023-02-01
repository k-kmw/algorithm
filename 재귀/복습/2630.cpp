#include <bits/stdc++.h>
using namespace std;
int board[130][130];
int result[2];

bool check(int x, int y, int n) {
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(board[x][y] != board[i][j])
                return false;
        }
    }
    return true;
}

void divide(int x, int y, int n) {
    if(check(x, y, n)) {
        result[board[x][y]]++;
    }
    else {
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                int half = n/2;
                divide(x+i*half, y+j*half, half);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    divide(0, 0, n);
    for(auto r:result)
        cout << r <<'\n';
}
