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
    if(check(x, y, n)) { // (x, y)를 n칸에 대해 같은지 체크
        result[board[x][y]+1]++; // 같으면 1을 추가함. (-1, 0, 1이므로 1을 더해서 추가)
        return ;
    }
    else { // 다를 경우 9개로 자름
        for(int i=0; i<3; i++) { // 행 3
            for(int j=0; j<3; j++) { // 열 3
                int size = n/3;
                divide(x+size*i, y+size*j, size);
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

    divide(0, 0, n); // (0, 0)에서 시작

    for(auto r : result)
        cout << r << '\n';
}
