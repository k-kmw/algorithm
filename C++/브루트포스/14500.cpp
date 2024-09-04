#include <bits/stdc++.h>
using namespace std;
int board[501][501];
int n, m;
int ans;
vector<vector<vector<int>>> dx = {
        {{0, 1, 2, 3},
         {0, 0, 0, 0}},

        {{0, 0, 1, 1}},

        {{0, 0, 0, 1},
         {0, 0, 1, 2},
         {0, 0, 0, -1},
         {0, 1, 2, 2},
         {0, 1, 1, 1},
         {0, 1, 2, 2},
         {0, 0, 1, 2},
         {0, 0, 0, 1}
         },

        {{0, 0, 1, 1},
         {0, 0, -1, -1},
         {0, 0, -1, 1},
         {0, 1, 1, 2}},

        {{0, 1, 1, 2},
         {0, 0, -1, 1},
         {0, 0, 0, 1},
         {0, 0, 0, -1}
        }};
vector<vector<vector<int>>> dy = {
        {{0, 0, 0, 0},
         {0, 1, 2, 3}},

        {{0, 1, 0, 1}},

        {{0, 1, 2, 2},
         {0, 1, 0, 0},
         {0, 1, 2, 2},
         {0, 0, 0, 1},
         {0, 0, 1, 2},
         {0, 0, 0, -1},
         {0, 1, 1, 1},
         {0, 1, 2, 0}
         },

        {{0, 1, 1, 2},
         {0, 1, 1, 2},
         {0, 1, 1, 0},
         {0, 0, 1, 1}},

        {{0, 0, 1, 0},
         {0, 1, 1, 1},
         {0, 1, 2, 1},
         {0, 1, 2, 1}
        }
};

void check(int y, int x) { // (x, y)에서 가능한 5가지 테트리미노를 모두 확인한다.
    for(int i=0; i<5; i++) { // 5가지 종류 각각의 테트로미노를 확인
        for(int j=0; j < dx[i].size(); j++) { // 다른 회전시킨 경우를 확인
            int tmp = 0;
            for(int k=0; k<dx[i][j].size(); k++) { // 한 종류의 하나의 방향의 테트로미노를 확인
                int nx = x + dx[i][j][k];
                int ny = y + dy[i][j][k];
                if(ny >= n || nx >= m || ny < 0 || nx < 0) {
                    tmp = 0;
                    break;
                }
                tmp += board[ny][nx];
            }
            ans = max(ans, tmp);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            check(i, j);
        }
    }
    cout << ans << '\n';
}