#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int cnt;
pair<int, int> blank[85];
bool isFinish;

bool lineHasSameNum(int boardCopy[10][10], int y, int x, int num) {
    // 같은 행 확인
    for(int j=0; j<9; j++) {
        if(boardCopy[y][j] == num) {
            return true;
        }
    }

    // 같은 열 확인
    for(int i=0; i<9; i++) {
        if(boardCopy[i][x] == num) {
            return true;
        }
    }

    return false;
}

bool squareHasSameNum(int boardCopy[10][10], int y, int x, int num) {
    int sty = 3*(y/3);
    int stx = 3*(x/3);
    for(int i=sty; i<sty+3; i++) {
        for(int j=stx; j<stx+3; j++) {
            if(boardCopy[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}

// k번째 빈칸을 결정
void dfs(int k, int boardCopy[10][10]) {
    if(isFinish) {
        return;
    }
    if(k == cnt) {
        for(int i=0; i<9; i++) {
            copy(boardCopy[i], boardCopy[i]+9, board[i]);
        }
        isFinish = true;
        return;
    }
//    cout << k << '\n';
    int tmp[10][10];
    for(int i=0; i<9; i++)
        copy(boardCopy[i], boardCopy[i]+9, tmp[i]);
    int y = blank[k].first;
    int x = blank[k].second;
    for(int i=1; i<=9; i++) {
        if(lineHasSameNum(boardCopy, y, x, i) || squareHasSameNum(boardCopy, y, x, i)) continue;
        tmp[y][x] = i;
        dfs(k+1, tmp);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) {
                blank[cnt++] = make_pair(i, j);
            }
        }
    }
    dfs(0, board);
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}