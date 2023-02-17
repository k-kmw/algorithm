#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[10][10];
vector<pair<int, int>> cctv;
int cctvNum;
int mn = 100;

void draw(int x, int y, int d) {
    int dir = d % 4;
    if(dir == 0) { // 상
        for(int i=x-1; i>=0; i--) {
            if(board[i][y] == 6)    break;
            if(board[i][y] != 0)    continue;
            board[i][y] = 7;
        }
    }

    if(dir == 1) { // 우
        for(int j=y+1; j<m; j++) {
            if(board[x][j] == 6)    break;
            if(board[x][j] != 0)    continue;
            board[x][j] = 7;
        }
    }

    if(dir == 2) { // 하
        for(int i=x+1; i<n; i++) {
            if(board[i][y] == 6)    break;
            if(board[i][y] != 0)    continue;
            board[i][y] = 7;
        }
    }

    if(dir == 3) { // 좌
        for(int j=y-1; j>=0; j--) {
            if(board[x][j] == 6)    break;
            if(board[x][j] != 0)    continue;
            board[x][j] = 7;
        }
    }
}

void func(int k) {
    if(k == cctvNum) { // 모든 cctv를 탐색한 후 사각지대 영역의 크기를 구함
        int area = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 0)
                    area++;
            }
        }
//        for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) {
//                cout << board[i][j] << ' ';
//            }
//            cout << '\n';
//        }
//        cout << '\n';
        mn = min(mn, area);
        return;
    }

    int boardTmp[10][10]; // 리턴 할 때 해당 스텝전까지 진행된 상태를 저장하기 위해 지역 변수로 사용
    // 전역 변수로 사용하면 리턴할때 이전 상태가 아니라 가장 최근 스텝(리턴하기 직전 함수)에서 진행한 상태가 되어 틀리게 됨
    // 해당 스택 영역마다 별개의 boardTmp가 존재
    int x = cctv[k].first; // 현재 cctv 좌표를 저장
    int y = cctv[k].second;

    for(int dir=0; dir<4; dir++) { // 4가지 경우를 살핌(2번의 경우 중복되는 경우가 생기지만 최소구역을 구하는 것이므로 상관없음)
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++){
                boardTmp[i][j] = board[i][j];
            }
        } // draw전 board를 tmp에 저장

        if(board[x][y] == 1) {
            draw(x, y, dir);
        }

        else if(board[x][y] == 2) {
            draw(x, y, dir);
            draw(x, y, dir+2);
        }

        else if(board[x][y] == 3) {
            draw(x, y, dir);
            draw(x, y, dir+1);
        }

        else if(board[x][y] == 4) {
            draw(x, y, dir);
            draw(x, y, dir+1);
            draw(x, y, dir+3);
        }

        else {
            draw(x, y, 0);
            draw(x, y, 1);
            draw(x, y, 2);
            draw(x, y, 3);
        } // 해당 cctv에 맞게 그린 후

        func(k+1); // 한 스텝 진행

        for(int i=0; i<n; i++) { // 한 스텝 진행 후 board를 이전 단계로 돌림, 돌린 상태에서 for문의 다음 번째 수행
            for(int j=0; j<m; j++){
                board[i][j] = boardTmp[i][j];
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6)
                cctv.emplace_back(i, j);
        }
    }
    cctvNum = cctv.size();
    func(0);
    cout << mn;
}

//백트래킹 풀이
