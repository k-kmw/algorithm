#include <bits/stdc++.h>
using namespace std;

int n;
int board[10][10];
vector< pair<int, int> > blank;
bool domino[100];
bool number[10][10];
bool isFinish;
bool used[10][10];

// k번째 자리의 도미노를 결정
void validateDomino(int k) { // 가능한 경우가 있는지 확인

    if(isFinish) {
        return;
    }

    if(k == blank.size()) {
        isFinish = true;
        return;
    }

    int row = blank[k].first;
    int col = blank[k].second;

    if(used[row][col]) {
        validateDomino(k+1);
        return;
    }

    // 가로 배치
    if(col+1 <= 9 && !used[row][col+1] && !number[row][col+1]) {
        int idx = board[row][col] * 10 + board[row][col + 1];
        int idx2 = board[row][col + 1] * 10 + board[row][col];
        if(!domino[idx] && !domino[idx2]) {
            domino[idx] = domino[idx2] = true;
            used[row][col] = used[row][col+1] = true;

            validateDomino(k+1);

            domino[idx] = domino[idx2] = false;
            used[row][col] = used[row][col+1] = false;
        }
    }
    // 세로 배치
    if(row+1 <= 9 && !used[row+1][col] && !number[row+1][col]) {
        int idx = board[row][col] * 10 + board[row+1][col];
        int idx2 = board[row+1][col] * 10 + board[row][col];
        if(!domino[idx] && !domino[idx2]) {
            domino[idx] = domino[idx2] = true;
            used[row][col] = used[row+1][col] = true;

            validateDomino(k+1);

            domino[idx] = domino[idx2] = false;
            used[row][col] = used[row+1][col] = false;
        }
    }
}

bool isValid(int row, int col, int num) {
    // 행에 같은 숫자가 있는지
    for(int j=1; j<=9; j++) {
        if(board[row][j] == num) {
            return false;
        }
    }

    // 열에 같은 숫자가 있는지
    for(int i=1; i<=9; i++) {
        if(board[i][col] == num) {
            return false;
        }
    }

    // 3x3에 같은 숫자가 있는지
    int rowSt = ((row-1)/3) * 3 + 1;
    int colSt = ((col-1)/3) * 3 + 1;
    for(int i=rowSt; i<rowSt+3; i++) {
        for(int j=colSt; j<colSt+3; j++) {
            if(board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// k번째 칸의 수를 결정
void dfs(int k) {

    if(isFinish) {
        return;
    }

    if(k == blank.size()) { // 전체 - 도미노 - 숫자
//        cout << k << '\n';
        validateDomino(0);
        return;
    }

    int row = blank[k].first;
    int col = blank[k].second;

    for(int i=1; i<=9; i++) {
        if(isValid(row, col, i)) {
//            cout << row << ' ' << col << ' ' << i << '\n';
            board[row][col] = i;
            dfs(k+1);
            if(isFinish) {
                return;
            }
            board[row][col] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 스도쿠 규칙에 따라 가능한 숫자 다 채우기
    // 2. 각 자리에서 가로/세로 선택하여 모든 도미노를 한 번씩 사용할 수 있는지 확인하기

    int t = 1;
    while(true) {
        blank.clear();
        fill(domino, domino+100, false);
        isFinish = false;
        for(int i=1; i<=9; i++) {
            fill(used[i], used[i]+10, false);
            fill(board[i], board[i]+10, 0);
            fill(number[i], number[i]+10, false);
        }
        cin >> n;
        if(n == 0)  break;
        for(int i=0; i<n; i++) {
            int a, b;
            string posA, posB;
            cin >> a >> posA >> b >> posB;
            domino[a*10+b] = true;
            domino[b*10+a] = true;
            int rowA = posA[0] - 'A' + 1;
            int colA = posA[1] - '0';
            int rowB = posB[0] - 'A' + 1;
            int colB = posB[1] - '0';
            board[rowA][colA] = a;
            board[rowB][colB] = b;
        }
        for(int i=1; i<=9; i++) {
            string pos;
            cin >> pos;
            int row = pos[0] - 'A' + 1;
            int col = pos[1] - '0';
            board[row][col] = i;
            number[row][col] = true;
        }

        for(int i=1; i<=9; i++) {
            for(int j=1; j<=9; j++) {
                if(board[i][j] == 0) {
                    blank.push_back(make_pair(i, j));
                }
            }
        }

        dfs(0);

        cout << "puzzle " << t++ << '\n';

        for(int i=1; i<=9; i++) {
            for(int j=1; j<=9; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
    }
}