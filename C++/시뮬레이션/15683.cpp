#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[10][10];
int area = 100;
int dx[] = {-1, 0,0, 1};
int dy[] = {0, -1, 1, 0};

void dfs(int k) {
    if(k == n*m) {
        int cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << board[i][j] << ' ';
                if(board[i][j] == 0)
                    cnt++;
            }
            cout << '\n';
        }
        area = min(area, cnt);
        return;
    }

    int x = k/m;
    int y = k%m;
    if(board[x][y] == 0 || board[x][y] == 6 || board[x][y] == 7) {
        dfs(k+1);
        return;
    }
    else if(board[x][y] == 1) {
        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            while(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != 6 ) {
                if(!board[nx][ny]) {
                    board[nx][ny] = 7;
                }
                nx += dx[dir];
                ny += dy[dir];
            }
            dfs(k+1);
            nx = x + dx[dir];
            ny = y + dy[dir];
            while(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != 6 ) {
                if(board[nx][ny] == 7) {
                    board[nx][ny] = 0;
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }

    else if(board[x][y] == 2) {
        // 위아래
        int nx = x - 1;
        while(nx >= 0 && board[nx][y] != 6) {
            if(!board[nx][y])
                board[nx][y] = 7;
            nx--;
        }

        nx = x + 1;
        while(nx < n && board[nx][y] != 6) {
            if(!board[nx][y])
                board[nx][y] = 7;
            nx++;
        }
        dfs(k+1);

        nx = x - 1;
        while(nx >= 0 && board[nx][y] != 6) {
            if(board[nx][y] == 7)
                board[nx][y] = 0;
            nx--;
        }

        nx = x + 1;
        while(nx < n && board[nx][y] != 6) {
            if(board[nx][y] == 7)
                board[nx][y] = 0;
            nx++;
        }

        // 좌우
        int ny = y - 1;
        while(ny >= 0 && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny--;
        }

        ny = y + 1;
        while(ny < m && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny++;
        }
        dfs(k+1);

        ny = y - 1;
        while(ny >= 0 && board[x][ny] != 6) {
            if(board[x][ny] == 7)
                board[x][ny] = 0;
            ny--;
        }

        ny = y + 1;
        while(ny < m && board[x][ny] != 6) {
            if(board[x][ny] == 7)
                board[x][ny] = 0;
            ny++;
        }
    }

    else if(board[x][y] == 3) {
        // 위
        int nx = x-1;
        while(nx >= 0 && board[nx][y] != 6) {
            if(!board[nx][y])
                board[nx][y] = 7;
            nx--;
        }

        // 오른쪽
        int ny = y+1;
        while(ny < m && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny++;
        }
        dfs(k+1);

        ny = y+1;
        while(ny < m && board[x][ny] != 6) {
            if(board[x][ny] == 7)
                board[x][ny] = 0;
            ny++;
        }

        // 왼쪽
        ny = y-1;
        while(ny >= 0 && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny--;
        }
        dfs(k+1);

        ny = y-1;
        while(ny >= 0 && board[x][ny] != 6) {
            if(board[x][ny] == 7)
                board[x][ny] = 0;
            ny--;
        }

        nx = x-1;
        while(nx >= 0 && board[nx][y] != 6) {
            if(board[nx][y] == 7)
                board[nx][y] = 0;
            nx--;
        }

        // 아래
        nx = x+1;
        while(nx < n && board[nx][y] != 6) {
            if(!board[nx][y])
                board[nx][y] = 7;
            nx++;
        }

        // 오른쪽
        ny = y+1;
        while(ny < m && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny++;
        }
        dfs(k+1);

        ny = y+1;
        while(ny < m && board[x][ny] != 6) {
            if(board[x][ny] == 7)
                board[x][ny] = 0;
            ny++;
        }

        // 왼쪽
        ny = y-1;
        while(ny >= 0 && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny--;
        }
        dfs(k+1);

        ny = y-1;
        while(ny >= 0 && board[x][ny] != 6) {
            if(board[x][ny] == 7)
                board[x][ny] = 0;
            ny--;
        }

        nx = x+1;
        while(nx < n && board[nx][y] != 6) {
            if(board[nx][y] == 7)
                board[nx][y] = 0;
            nx++;
        }
    }

    else if(board[x][y] == 4) {
        // 위
        int nx = x-1;
        while(nx >= 0 && board[nx][y] != 6) {
            if(!board[nx][y])
                board[nx][y] = 7;
            nx--;
        }
        // 좌
        int ny = y-1;
        while(ny >= 0 && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny--;
        }
        // 우
        ny = y+1;
        while(ny < m && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny++;
        }
        dfs(k+1);

        // 위 원복
        nx = x-1;
        while(nx >= 0 && board[nx][y] != 6) {
            if(board[nx][y] == 7)
                board[nx][y] = 0;
            nx--;
        }

        // 아래
        nx = x+1;
        while(nx < n && board[nx][y] != 6) {
            if(!board[nx][y])
                board[nx][y] = 7;
            nx++;
        }
        dfs(k+1);

        // 우 원복
        ny = y + 1;
        while(ny < m && board[x][ny] != 6) {
            if(board[x][ny] == 7)
                board[x][ny] = 0;
            ny++;
        }

        // 위
        nx = x-1;
        while(nx >= 0 && board[nx][y] != 6) {
            if(!board[nx][y])
                board[nx][y] = 7;
            nx--;
        }
        dfs(k+1);

        // 좌 원복
        ny = y - 1;
        while(ny >= 0 && board[x][ny] != 6) {
            if(board[x][ny] == 7)
                board[x][ny] = 0;
            ny--;
        }

        // 우
        ny = y + 1;
        while(ny < m && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny++;
        }
        dfs(k+1);

        // 아래 원복
        nx = x+1;
        while(nx < n && board[nx][y] != 6) {
            if(board[nx][y] == 7)
                board[nx][y] = 0;
            nx++;
        }

        // 우 원복
        ny = y+1;
        while(ny < m && board[x][ny] != 6) {
            if(board[x][ny] == 7)
                board[x][ny] = 0;
            ny++;
        }

        // 위 원복
        nx = x-1;
        while(nx >= 0 && board[nx][y] != 6) {
            if(board[nx][y] == 7)
                board[nx][y] = 0;
            nx--;
        }
    }

    else {
        // 위
        int nx = x-1;
        while(nx >= 0 && board[nx][y] != 6) {
            if(!board[nx][y])
                board[nx][y] = 7;
            nx--;
        }
        // 좌
        int ny = y-1;
        while(ny >= 0 && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny--;
        }
        // 우
        ny = y+1;
        while(ny < m && board[x][ny] != 6) {
            if(!board[x][ny])
                board[x][ny] = 7;
            ny++;
        }
        // 아래
        nx = x+1;
        while(nx < n && board[nx][y] != 6) {
            if(!board[nx][y])
                board[nx][y] = 7;
            nx++;
        }
        dfs(k+1);

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    dfs(0);
    cout << area;
}

