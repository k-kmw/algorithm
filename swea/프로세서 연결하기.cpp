#include <bits/stdc++.h>
using namespace std;

int mn = 12*12+1;
int board[15][15];
int n;
vector<pair<int, int>> cores; // core의 좌표
pair<int, int> selected[15];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

// k번째 core를 연결. line: 총 전선 길이, cnt: 연결된 core 수
void dfs(int k, int line, int r, int cboard[15][15]) {

    int board2[15][15];

    for(int i=0; i<n; i++)
        copy(cboard[i], cboard[i]+n, board2[i]);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board2[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    if(k == r) {
        mn = min(mn, line);
        return;
    }

    auto core = selected[k];
    for(int dir=0; dir<4; dir++) {

        int y = core.first;
        int x = core.second;
        int tmp = 0;
        bool isSuccess = false;

        while(true) {
            y += dy[dir];
            x += dx[dir];
            if (y < 0 || y >= n || x < 0 || x >= n) {
                isSuccess = true;
                break;
            }
            if (board2[y][x] == 1 || board2[y][x] == 2) {
                break;
            }
            board2[y][x] = 2;
            tmp++;
        }
        cout << k << '\n';
        if(isSuccess) {
            dfs(k + 1, line + tmp, r, board2);
        } else {
            while(true) { // 원 상태로 돌려놓기
                x -= dx[dir]; y -= dy[dir];
                if(x == core.second && y == core.first) break;
                board2[y][x] = 0;
            }
        }
    }
}

// k번째 core를 결정
void subSet(int k, int st, int r, int cboard[15][15]) {
    if(k == r) {
        dfs(0, 0, r, cboard);
        return;
    }
    for(int i=st; i<cores.size(); i++) {
        selected[k] = cores[i];
        subSet(k+1, i+1, r, cboard);
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++) {

        // 1. core를 R개 선택하는 부분집합을 구한다. 이때 R은 core전체부터 0까지 진행.
        // 2. 구한 조합에 대해 4방향 전선을 연결을 시도한다. 만약 연결되지 않으면 return 후 다른 조합 탐색
        // 3. 가능한 경우 최소값 갱신
        // 4. R개의 부분집합의 조합에서 최소값이 갱신되었으면 종료
        cores.clear();
        mn = 12*12+1;
        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> board[i][j];
                if(board[i][j] == 1 && i > 0 && i < n-1 && j > 0 && j < n-1) {
                    cores.push_back({i, j});
                }
            }
        }

        int sz = cores.size();
        for(int r=sz; r>=0; r--) {
            subSet(0, 0, r, board);
            if(mn != 12*12+1) {
                cout << "#" << test_case << " ";
                cout << mn << '\n';
                break;
            }
        }

    }
}