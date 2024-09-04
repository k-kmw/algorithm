#include <bits/stdc++.h>
using namespace std;

int n;
char board[51][51];

class Tree {
public:
    int y, x, dir, cnt;
    Tree(int y, int x, int dir, int cnt) {
        this->y = y;
        this->x = x;
        this->dir = dir; // 방향 0이면 가로, 1이면 세로
        this->cnt = cnt;
    }
};

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int d[2][2] = {{0, 1}, {1, 0}}; // 가로, 세로
int rotY[2][6] = {{1, 1, 1, -1, -1, -1}, {-1, 0, 1, -1, 0, 1}}; // 가로, 세로
int rotX[2][6] = {{-1, 0, 1, -1, 0, 1}, {-1, -1, -1, 1, 1, 1}};
bool vis[51][51][2]; // 방향까지 고려
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 통나무 길이 항상 3, B의 개수와 E의 개수 같음
    // 통나무는 가운데 점의 좌표, 방향으로 구성
    // 1. 통나무를 큐에 넣고 bfs
    // 2. 상, 하, 좌, 우 4방향 + 회전하여 큐에 넣음
    // 3. 목적지 도착할 때 까지 반복

    cin >> n;
    int cnt = 0;
    int cnt2 = 0;
    int destY = -1;
    int destX = -1;
    Tree tree = Tree(0, 0, 0, 0);
    int preY = -1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];

            if(board[i][j] == 'E' && cnt2 == 0) {
                cnt2++;
            }
            else if(board[i][j] == 'E' && cnt2 == 1) {
                destY = i;
                destX = j;
                cnt2++;
            }

            if(board[i][j] == 'B' && cnt == 0)  {
                cnt++;
                preY = i;
            }
            else if(board[i][j] == 'B' && cnt == 1) {
                tree.y = i;
                tree.x = j;
                if(preY == i) { // 통나무 가로
                    tree.dir = 0;
                } else { // 통나무 세로
                    tree.dir = 1;
                }
                cnt++;
            }
        }
    }

    queue<Tree> q;
    q.push(tree);
    vis[tree.y][tree.x][tree.dir] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

//        cout << cur.y << ' ' <<  cur.x << ' ' <<  cur.dir << ' ' << cur.cnt << '\n';

        if(cur.y == destY && cur.x == destX) {
            cout << cur.cnt << '\n';
            return 0;
        }

        for(int dir=0; dir<4; dir++) { // 상, 하, 좌, 우 4방향 이동
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if(vis[ny][nx][cur.dir])  continue;
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == '1')    continue;
            int ny2 = cur.y + d[cur.dir][0] + dy[dir];
            int nx2 = cur.x + d[cur.dir][1] + dx[dir];
            if(ny2 < 0 || ny2 >= n || nx2 < 0 || nx2 >= n || board[ny2][nx2] == '1')    continue;
            int ny3 = cur.y - d[cur.dir][0] + dy[dir];
            int nx3 = cur.x - d[cur.dir][1] + dx[dir];
            if(ny3 < 0 || ny3 >= n || nx3 < 0 || nx3 >= n || board[ny3][nx3] == '1')    continue;
            vis[ny][nx][cur.dir] = true;
            q.push(Tree(ny, nx, cur.dir, cur.cnt + 1));
        }
        // 회전
        int ny = 0;
        int nx = 0;
        if(cur.dir == 0) { // 가로일 경우

            if(vis[cur.y][cur.x][1])    continue;

            bool isPossible = true;

            for(int dir=0; dir<6; dir++) {
                ny = cur.y + rotY[0][dir];
                nx = cur.x + rotX[0][dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == '1') {
                    isPossible = false;
                    break;
                }
            }
            if(isPossible) {
                vis[cur.y][cur.x][1] = true;
                q.push(Tree(cur.y, cur.x, 1, cur.cnt+1));
            }
        } else { // 세로일 경우
            if(vis[cur.y][cur.x][0])    continue;

            bool isPossible = true;
            for(int dir=0; dir<6; dir++) {
                ny = cur.y + rotY[1][dir];
                nx = cur.x + rotX[1][dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == '1') {
                    isPossible = false;
                    break;
                }
            }
            if(isPossible) {
                vis[cur.y][cur.x][0] = true;
                q.push(Tree(cur.y, cur.x, 0, cur.cnt+1));
            }
        }
    }
    cout << 0 << '\n';
}