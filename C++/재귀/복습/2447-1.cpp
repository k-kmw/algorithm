#include <bits/stdc++.h>
using namespace std;
char board[2300][2300];

void star(int row, int col, int n) {
    if(n == 1)  {
        board[row][col] = '*';
        return;
    } // n=1일 때 *를 저장하고 리턴
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i==1 && j==1)
                continue; // 가운데가 비어 있으므로 그리지 않음.
            star(row+i*n/3, col+j*n/3, n/3); // n/3칸 짜리를 연속 적으로 그린다
        }
    }
    // 초기 n크기와 상관없이 n에서 n/3을 그리고 그 안에서 다시 n/3한 것을 그리고.. 이것을 n=1이 될 때까지 반복함
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        fill(board[i], board[i]+n, ' ');
    star(0, 0, n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout << board[i][j];
        cout << '\n';
    }
}
