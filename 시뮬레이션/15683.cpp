#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[10][10];
int tmp[10][10];
int mn = 64;

void move() {
    for(int a=0; a<n; a++) {
        for(int b=0; b<m; b++)
            board[a][b] = tmp[a][b];
    }
}

int check() {
    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(tmp[i][j] == 0)
                cnt ++;
        }
    }
    for(int a=0; a<n; a++) {
        for(int b=0; b<m; b++)
            tmp[a][b] = board[a][b];
    }
    cout << cnt << '\n';
    return cnt;
}


void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << tmp[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            tmp[i][j] = board[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int cnt;
            if(board[i][j] == 1) {
                int st = j; // 우측
                for(int a = st+1; a<m; a++) {
                    if(tmp[i][a] == 6)    break;
                    tmp[i][a] = 7;
                }
                cnt = check();
                mn = min(mn, cnt);

                // 좌측
                for(int a = st-1; a>=0; a--) {
                    if (tmp[i][a] == 6) break;
                    tmp[i][a] = 7;
                }
                cnt = check();
                mn = min(mn, cnt);

                // 위쪽
                st = i;
                for(int a = st-1; a>=0; a--) {
                    if (tmp[a][j] == 6) break;
                    tmp[a][j] = 7;
                }
                cnt = check();
                mn = min(mn, cnt);

                // 아래
                for(int a = st+1; a<n; a++) {
                    if (tmp[a][j] == 6) break;
                    tmp[a][j] = 7;
                }
                cnt = check();
                mn = min(mn, cnt);


            }

            if(board[i][j] == 2) {
                int st = j;
                // 우
                for(int a=st; a<m; a++) {
                    if(tmp[i][a] == 6)  break;
                    tmp[i][a] = 7;
                }
                cnt =
                // 좌
                for(int a=st; a<m; a++) {
                    if(tmp[i][a] == 6)  break;
                    tmp[i][a] = 7;
                }
        }

        }
    }

}

