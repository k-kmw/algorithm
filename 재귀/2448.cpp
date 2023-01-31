#include <bits/stdc++.h>
using namespace std;
char board[3100][6200];

void star(int row, int col, int height) {
    if(height == 3) {
        board[row][col] = '*';
        board[row+1][col-1] = '*';
        board[row+1][col+1] = '*';
        for(int i=0; i<5; i++) {
            board[row+2][col-2+i] = '*';
        }
        return;
    }
    star(row, col, height/2);
    star(row+height/2, col-height/2, height/2);
    star(row+height/2, col+height/2, height/2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<2*n-1; j++)
            board[i][j] = ' ';
    star(0, n-1, n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<2*n-1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

// 답 참고해서 품..