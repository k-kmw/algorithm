#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[] = {-1, 0, 1, 0}; // 상 우 하 좌
int dy[] = {0, 1, 0, -1};
int board[10][10];
int board2[10][10];
vector<pair<int, int>> cctv;
int cctvNum;

bool valid(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >=m)   return false;
    return true;
}

void update(int x, int y, int dir) {
    dir = dir % 4;
    while(1) {
        x += dx[dir]; // x, y를 dir방향으로 이동
        y += dy[dir];
        if(valid(x, y)) { // 유효한 좌표이면
            if(board2[x][y] == 6)  return; // 벽을 만나면 return
            if(board2[x][y] != 0)  continue; // cctv이면 continue
            board2[x][y] = 7; //cctv 영역안이면 7로 바꿈
        }
        else {
            return;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int mn = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6) {
                cctv.emplace_back(i, j);
                cctvNum++;
            }
            if(board[i][j] == 0)
                mn++; //처음에 최초 사각지대의 개수를 구함. cctv가 0개일 경우를 고려
        }
    }

    for(int tmp=0; tmp< (1<<(2*cctvNum)); tmp++) { // cctv하나당 가능한 방향이 4개 이므로 4^cctv개수
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                board2[i][j] = board[i][j];
            } // board2에 board를 복사
        }
        int brute = tmp; // 4진수로 변환할 10진수
        int dir;
        for(int i=0; i<cctvNum; i++) { //cctv 개수만큼 반복
            dir = brute % 4; //4진수 값 구하기(방향 0~3)
            brute /= 4; // 다음 4진수 값 구하기(다음 cctv 방향)
            int x = cctv[i].first; //i번째 cctv 좌표
            int y = cctv[i].second;
            if(board[x][y] == 1) {
                update(x, y, dir);
            }
            else if(board[x][y] == 2) {
                update(x, y, dir);
                update(x, y, dir+2);
            }
            else if(board[x][y] == 3) {
                update(x, y, dir);
                update(x, y, dir+1);
            }
            else if(board[x][y] == 4) {
                update(x, y, dir);
                update(x, y, dir+1);
                update(x, y, dir+2);
            }
            else {
                update(x, y, 0);
                update(x, y, 1);
                update(x, y, 2);
                update(x, y, 3);
            }
        }

        int val=0;
        for(int i=0; i<n; i++) { //매 케이스마다 사각지대 영역이 최소인지 확인
            for(int j=0; j<m; j++) {
                if(board2[i][j] == 0) {
                    val++;
                }
            }
        }
        mn = min(mn, val);
    }
    cout << mn;
}

// 삼성 A형 기출. 다시 풀어보기.
