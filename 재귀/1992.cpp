#include <bits/stdc++.h>
using namespace std;
char board[65][65];
int N;

bool check(int x, int y, int n) {
    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            if(board[x][y] != board[i][j])
                return false;
    return true;

}

void quad(int x, int y, int n) {
    if(check(x, y, n)) {
        cout << board[x][y];
    }
    else {
        cout << '(';
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                quad(x+i*n/2, y+j*n/2, n/2);
        cout << ')';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    quad(0, 0, N);
}