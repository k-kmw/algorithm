#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
bool vis[100][100];

int solution(vector<string> board) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    pair<int, int> goal;
    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 'R') {
                q.push({{i, j}, 0});
                vis[i][j] = true;
            } else if(board[i][j] == 'G') {
                goal = {i, j};
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        int y = cur.first.first;
        int x = cur.first.second;
        int cnt = cur.second;

        for(int dir=0; dir<4; dir++) {

            int ny = y;
            int nx = x;
            while(true) {
                ny += dy[dir];
                nx += dx[dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == 'D') {
                    ny -= dy[dir];
                    nx -= dx[dir];
                    break;
                }
            }
            if(ny == goal.first && nx == goal.second) {
                return cnt+1;
            }
            if(vis[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push({{ny, nx}, cnt+1});
        }
    }
    return -1;
}