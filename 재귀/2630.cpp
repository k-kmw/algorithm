#include <bits/stdc++.h>
using namespace std;
int board[130][130];
int result[2];
int N;

bool check(int x, int y, int n) { // 같은지 확인 하는 함수
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
        result[board[x][y]]++;
    }
    else {
        int size = n / 2;
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                divide(x+i*size, y+j*size, size);
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
    for(auto res:result)
        cout << res << '\n';
}