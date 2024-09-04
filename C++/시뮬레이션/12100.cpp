#include <bits/stdc++.h>
using namespace std;
int n;
int board[20][20];
int mx;
void getMax() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            mx = max(board[i][j], mx);
        }
    }
}

void sort(int dir) {
    if(dir == 0) { //상
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[j][i] == 0) {
                    for(int k=j+1; k<n; k++) {
                        if(board[k][i] != 0) {
                            board[j][i] = board[k][i];
                            board[k][i] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(dir == 1) { //우
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=1; j--) {
                if(board[i][j] == 0) {
                    for(int k=j-1; k>=0; k--) {
                        if(board[i][k] != 0) {
                            board[i][j] = board[i][k];
                            board[i][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(dir == 2) { //좌
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 0) {
                    for(int k=j+1; k<n; k++) {
                        if(board[i][k] != 0) {
                            board[i][j] = board[i][k];
                            board[i][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(dir == 3) { //하
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=1; j--) {
                if(board[j][i] == 0) {
                    for(int k=j-1; k>=0; k--) {
                        if(board[k][i] != 0) {
                            board[j][i] = board[k][i];
                            board[k][i] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void move(int dir) {
    sort(dir);
    if(dir == 0) { //상
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-1; j++) {
                if(board[j][i] == board[j+1][i] && board[j][i] != 0) {
                    board[j][i] += board[j+1][i];
                    board[j+1][i] = 0;
                }
            }
        }
    }
    if(dir == 1) { // 우
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=1; j--) {
                if(board[i][j] == board[i][j-1] && board[i][j] != 0) {
                    board[i][j] += board[i][j-1];
                    board[i][j-1] = 0;
                }
            }
        }
    }

    if(dir == 2) { // 좌
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-1; j++) {
                if(board[i][j] == board[i][j+1] && board[i][j] != 0) {
                    board[i][j] += board[i][j+1];
                    board[i][j+1] = 0;
                }
            }
        }
    }
    if(dir == 3) { //하
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=1; j--) {
                if(board[j][i] == board[j-1][i] && board[j][i] != 0) {
                    board[j][i] += board[j-1][i];
                    board[j-1][i] = 0;
                }
            }
        }
    }

    sort(dir);

//    for(int i=0; i<n; i++) {
//        for(int j=0; j<n; j++) {
//            cout << board[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';

}

void setDir(int k) {
    if(k == 5) {
        getMax();
        return;
    }

    int tmp[20][20];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            tmp[i][j] = board[i][j]; //백트래킹 작업전 tmp에 board를 저장

    for(int dir=0; dir<4; dir++) {
        move(dir);
        setDir(k+1);

        for(int i=0; i<n; i++) //한 방향으로 모두 트래킹 후 다음차례 반복전 이전 트래킹 전의 상태로 돌림
            for(int j=0; j<n; j++)
                board[i][j] = tmp[i][j];
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    setDir(0);
    cout << mx;
}

