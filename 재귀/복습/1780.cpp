#include <bits/stdc++.h>
using namespace std;
int board[2200][2200];
int result[3];

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
        result[board[x][y]+1]++;
        return ;
    }
    else {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                divide(x+n/3*i, y+n/3*j, n/3);
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

    for(auto r : result)
        cout << r << '\n';
}
