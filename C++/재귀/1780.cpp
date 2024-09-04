#include <bits/stdc++.h>
using namespace std;

int N;
int board[2200][2200];
int result[3];

bool check(int x, int y, int n) { // 같은지 체크
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(board[x][y] != board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void divide(int x, int y, int n) {
    if(check(x, y, n)) {
        result[board[x][y]+1]++;
    }
    else {
        int size = n / 3;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                divide(x + size*i, y+size*j, size);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    divide(0, 0, N);
    for(auto r : result) {
        cout << r << '\n';
    }
}