#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int board[40][40];
int sticker[10][10];
int rotSticker[10][10];
int idx, idy;

bool check(int r, int c) {
    if(r > n || c > m)  return false; // 스티커가 노트북보다 크면 false

    for(int i=0; i<=n-r; i++) {
        for(int j=0; j<=m-c; j++) {
            bool check = true;
            for(int a=i; a<i+r; a++) {
                for(int b=j; b<j+c; b++) {
                    if(board[a][b] == 1 && sticker[a-i][b-j] == 1) { //노트북의 해당 위치와 스티커가 모두 1이면 붙일 수 없음
                        check = false;
                    }
                }
            }
            if(check) { // 시작 지점
                idx = i; // 행 시작점
                idy = j; // 열 시작점
                return true;
            }
        }
    }
    return false;
}

void rotate(int r, int c) {
    for(int i=0; i<10; i++)
        fill(rotSticker[i], rotSticker[i]+10, 0); //rotSticker를 초기화 시켜줌

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            rotSticker[j][r-i-1] = sticker[i][j]; //sticker를 회전시킴
        }
    }

    for(int i=0; i<10; i++) { //sticker에 rotSticker를 옮김
        for(int j=0; j<10; j++) {
            sticker[i][j] = rotSticker[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while(k--) {
        int r, c;
        cin >> r >> c;

        for(int i=0; i<10; i++) //stickr 초기화
            fill(sticker[i], sticker[i]+10, 0);

        for(int i=0; i<r; i++) //sticker 입력 받음
            for(int j=0; j<c; j++)
                cin >> sticker[i][j];

        for(int dir=0; dir<4; dir++) { //4번의 회전 가능
            if (check(r, c)) { //붙일 수 있으면
                for (int i = idx; i < idx + r; i++) { //x 시작점에서 r만큼 붙임
                    for (int j = idy; j < idy + c; j++) { //y 시작점에서 c만큼 붙임
                        if(sticker[i-idx][j-idy] == 1)
                            board[i][j] = sticker[i - idx][j - idy];
                    }
                }
                break; //붙이고 나감
            } else { //붙일 수 없을 경우 회전 시킴
                rotate(r, c);
                swap(r, c); //행과 열이 바뀌므로 r과 c 값 바꿔줌
            }
        }

//        for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) {
//                cout << board[i][j] << ' ';
//            }
//            cout << '\n';
//        }
//        cout << '\n';
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            if(board[i][j] == 1)
                ans++;
        }
    }
    cout << ans;
}

//ans 지역변수 초기화 안해주고 사용해서 틀림
