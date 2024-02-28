#include <bits/stdc++.h>
using namespace std;

class Brick {
public:
    int y, x;
    int num;

    Brick(int y, int x, int num) {
        this->y = y;
        this->x = x;
        this->num = num;
    }
};

queue<Brick> bricks;
int board[20][20];
int n, w, h;
vector<int> pos;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int mn = 20*20;

// 구슬을 파괴
void destroy() {

    int boardCopy[20][20];
    for(int i=0; i<h; i++) {
        copy(board[i], board[i]+w, boardCopy[i]);
    }

    // 모든 구슬에 대해 수행
    for (int p : pos) {
        // 첫번째 원소 찾기
        for (int i = 0; i < h; i++) {
            if (boardCopy[i][p] != 0) {
                bricks.push(*new Brick(i, p, boardCopy[i][p]));
                break;
            }
        }
        // 첫번째 원소를 시작으로 폭발 연쇄적으로 시키기
        while (!bricks.empty()) {
            auto brick = bricks.front();
            bricks.pop();

            boardCopy[brick.y][brick.x] = 0;
            for (int dir = 0; dir < 4; dir++) {
                int y = brick.y;
                int x = brick.x;
                int num = brick.num-1;
                while (num-- > 0) {
//                    cout << y << x << '\n';
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny < 0 || ny >= h || nx < 0 || nx >= w) break;
                    y = ny;
                    x = nx;
                    if(boardCopy[ny][nx] == 0)  continue;
                    bricks.push(*new Brick(ny, nx, boardCopy[ny][nx]));
                    boardCopy[ny][nx] = 0;
                }
            }
        }

        // 빈칸 있으면 아래로 이동
        for(int j=0; j<w; j++) {
            for(int i=h-1; i>=0; i--) {
                if(boardCopy[i][j] != 0) {
                    int k = i + 1;
                    while(k < h && boardCopy[k][j] == 0) {
                        k++;
                    }
                    if (k - 1 != i) {
                        boardCopy[k - 1][j] = boardCopy[i][j];
                        boardCopy[i][j] = 0;
                    }
                }
            }
        }

//    if(pos[0] == 2 && pos[1] == 2 && pos[2] == 6) {
//        for(auto& p : pos) {
//            cout << p << ' ';
//        }
//        cout << '\n';
        int tmp = 0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
//                cout << boardCopy[i][j] << ' ';
                if(boardCopy[i][j] != 0) {
                    tmp++;
                }
            }
//            cout << '\n';
        }
//        cout << '\n';
        mn = min(mn, tmp);
    }
}

// k번째 구슬을 떨어뜨릴 위치를 구함
void findPos(int k) {

    if (k == n) {
        destroy();
        return;
    }

    for (int i = 0; i < w; i++) {
        pos.push_back(i);
        findPos(k + 1);
        pos.pop_back();
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        mn = 20*20;
        cin >> n >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
            }
        }

        // 1. n개의 구슬 떨어뜨릴 위치 구하기
        // 2. 벽돌 깨면서 경로에 있는 연쇄적인 벽돌 벡터에 넣기
        // 3. 벡터 순회하면서 연쇄적인 벽돌 다 깨기
        // 4. 남은 벽돌 최소값 갱신

        findPos(0);

        cout << "#" << test_case << " " << mn << '\n';
    }
}