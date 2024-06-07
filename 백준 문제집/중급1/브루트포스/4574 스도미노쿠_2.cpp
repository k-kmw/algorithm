#include <bits/stdc++.h>
using namespace std;

int n;
bool isFinish;
vector< pair<int, int> > blank;
bool vis[10][10];
bool isNum[10][10];
int t = 1;

bool validSdokuNum(int board[10][10], int row, int col, int num) {
    // 행에 같은 숫자가 있는지
    for(int j=0; j<9; j++) {
        if(board[row][j] == num) {
            return false;
        }
    }

    // 열에 같은 숫자가 있는지
    for(int i=0; i<9; i++) {
        if(board[i][col] == num) {
            return false;
        }
    }

    // 3x3에 같은 숫자가 있는지
    int rowSt = (row/3) * 3;
    int colSt = (col/3) * 3;
    for(int i=rowSt; i<rowSt+3; i++) {
        for(int j=colSt; j<colSt+3; j++) {
            if(board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// k번째 빈칸의 숫자를 결정
void dfs(int k, int board[10][10], bool domino[10][10]) {

    if(isFinish) {
        return;
    }

//    cout << k << '\n';

//    for(int i=0; i<9; i++) {
//        for(int j=0; j<9; j++) {
//            cout << board[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    if(k == blank.size()) {
        isFinish = true;
        cout << "Puzzle " << t++ << '\n';
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
        return;
    }

    int row = blank[k].first;
    int col = blank[k].second;

    if(vis[row][col]) {
        dfs(k+1, board, domino);
        return;
    }

    for(int i=1; i<=9; i++) {
        if(!validSdokuNum(board, row, col, i)) continue;
        for(int j=1; j<=9; j++) {
            if(i == j) continue;

            if(domino[i][j] || domino[j][i]) continue; // 이미 도미노를 사용한 경우

            // 가로로 놓기
            if(col+1 < 9 && board[row][col+1] == 0 && validSdokuNum(board, row, col+1, j) && !isNum[row][col+1]) {
                board[row][col] = i;
                board[row][col+1] = j;
                domino[i][j] = domino[j][i] = true;
                vis[row][col] = vis[row][col+1] = true;

                dfs(k+1, board, domino);

                board[row][col] = 0;
                board[row][col+1] = 0;
                domino[i][j] = domino[j][i] = false;
                vis[row][col] = vis[row][col+1] = false;
            }

            // 세로로 놓기
            if(row+1 < 9 && board[row+1][col] == 0 && validSdokuNum(board, row+1, col, j) && !isNum[row+1][col]) {
                board[row][col] = i;
                board[row+1][col] = j;
                domino[i][j] = domino[j][i] = true;
                vis[row][col] = vis[row+1][col] = true;

                dfs(k+1, board, domino);

                board[row][col] = 0;
                board[row+1][col] = 0;
                domino[i][j] = domino[j][i] = false;
                vis[row][col] = vis[row+1][col] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. k번째 빈칸에 대해 1~9까지 스도쿠 규칙을 만족하는지 검사
    // => 만족하지 않으면 다음 숫자를 검사
    // 2. 1번 조건을 만족하는 경우 4방향 탐색을 통해 이미 사용중인 도미노가 아닌지 검사
    // => 이미 사용중인 도미노일 경우 다음 숫자를 검사

    while(true) {
        cin >> n;
        if(n == 0) {
            break;
        }
        int board[10][10];
        bool domino[10][10];
        blank.clear();
        for(int i=0; i<10; i++) {
            fill(board[i], board[i]+10, 0);
            fill(domino[i], domino[i]+10, false);
            fill(vis[i], vis[i]+10, false);
            fill(isNum[i], isNum[i]+10, false);
        }
        isFinish = false;
        for(int i=0; i<n; i++) {
            int a, b;
            string posA, posB;
            cin >> a >> posA >> b >> posB;
            int rowA = posA[0] - 'A';
            int colA = posA[1] - '0' - 1;
            int rowB = posB[0] - 'A';
            int colB = posB[1] - '0' - 1;
            domino[a][b] = domino[b][a] = true;
            board[rowA][colA] = a;
            board[rowB][colB] = b;
        }

        for(int i=1; i<=9; i++) {
            string pos;
            cin >> pos;
            int row = pos[0] - 'A';
            int col = pos[1] - '0' -1;
            board[row][col] = i;
            isNum[row][col] = true;
        }

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == 0) {
                    blank.push_back(make_pair(i, j));
                }
            }
        }
        dfs(0, board, domino);
    }
}