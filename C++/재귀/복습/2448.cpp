#include <bits/stdc++.h>
using namespace std;
char board[4000][4000];

void star(int row, int col, int n) {
    if(n==3) {
        board[row][col] = '*';
        board[row+1][col-1] = '*';
        board[row+1][col+1] = '*';
        for(int i=0; i<5; i++)
            board[row+2][col-2+i] = '*';
        return;
    }
    int height = n/2;
    star(row, col, n/2);
    star(row+height, col-height, n/2);
    star(row+height, col+height, n/2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        fill(board[i], board[i]+(2*n-1), ' ');

    star(0, n-1, n);
    for(int i=0; i<n; i++)
        cout << board[i] << '\n';
}
