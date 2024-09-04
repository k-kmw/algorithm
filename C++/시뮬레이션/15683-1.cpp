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
    if(k == cctvNum) {
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
    // 전역 변수로 사용하면 리턴할때 이전 상태가 아니라 가장 최근 스텝에서 진행한 상태가 되어 틀리게 됨
    int x = cctv[k].first; // 현재 cctv 좌표를 저장
    int y = cctv[k].second;
    if(board[x][y] == 1) {
        for(int dir=0; dir<4; dir++) {

            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++){
                    boardTmp[i][j] = board[i][j];
                }
            }
            draw(x, y, dir);
            func(k+1);
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++){
                    board[i][j] = boardTmp[i][j];
                }
            }

        }
    }

    else if(board[x][y] == 2) {
        for(int dir=0; dir<2; dir++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++){
                    boardTmp[i][j] = board[i][j];
                }
            }
            draw(x, y, dir);
            draw(x, y, dir+2);
            func(k+1);
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++){
                    board[i][j] = boardTmp[i][j];
                }
            }
        }
    }

    else if(board[x][y] == 3) {
        for(int dir=0; dir<4; dir++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++){
                    boardTmp[i][j] = board[i][j];
                }
            }
            draw(x, y, dir);
            draw(x, y, dir+1);
            func(k+1);
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++){
                    board[i][j] = boardTmp[i][j];
                }
            }
        }
    }

    else if(board[x][y] == 4) {
        for(int dir=0; dir<4; dir++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++){
                    boardTmp[i][j] = board[i][j];
                }
            }
            draw(x, y, dir);
            draw(x, y, dir+1);
            draw(x, y, dir+3);
            func(k+1);
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++){
                    board[i][j] = boardTmp[i][j];
                }
            }
        }
    }
    else {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++){
                boardTmp[i][j] = board[i][j];
            }
        }
        draw(x, y, 0);
        draw(x, y, 1);
        draw(x, y, 2);
        draw(x, y, 3);
        func(k+1);
        for(int i=0; i<n; i++) {
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

