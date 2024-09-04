#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[16][16];
int mx = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dx2[] = {-1, -1, 1, 1};
int dy2[] = {1, -1, -1, 1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 모든 칸에 대하여 스프레이를 분사한다.
    // 2. 각 칸에서 분사했을 경우 +/x 두 경우를 비교하여 최대값을 갱신한다
    // 2-1. 범위를 벗어나는 경우
    int test_case;
    int T;
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> board[i][j];
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int sum = board[i][j];
                int level = 1;
                while(level < m) {
                    for(int dir=0; dir<4; dir++) {
                        int curY = i + level*dy[dir];
                        int curX = j + level*dx[dir];
                        if(curX >= 0 && curX < n && curY >= 0 && curY < n) {
                            sum += board[curY][curX];
                            // cout << "TEST " << sum << '\n';
                        }
                    }
                    level++;
                }
                mx = max(sum, mx);
                sum = board[i][j];
                level = 1;
                while(level < m) {
                    for(int dir=0; dir<4; dir++) {
                        int curY = i + level*dy2[dir];
                        int curX = j + level*dx2[dir];
                        if(curX >= 0 && curX < n && curY >= 0 && curY < n) {
                            sum += board[curY][curX];
                            // cout << "TES2T " << sum << '\n';
                        }
                    }
                    level++;
                }
                mx = max(sum, mx);
                level = 1;
            }
        }
        cout << '#' << test_case << ' ' << mx << '\n';
        mx = 0;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
