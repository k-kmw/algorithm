#include <bits/stdc++.h>
using namespace std;
int n;
int board[20][20];
int board2[20][20];
int mx;

void rotate() {
    int tmp[20][20] = {};
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            tmp[j][n-1-i] = board2[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            board2[i][j] = tmp[i][j];
        }
    }

}

void tilt(int dir) {
    while(dir--) rotate();

    for(int i=0; i<n; i++) {
        int tilt[20] = {};
        int idx = 0;
        for(int j=0; j<n; j++) {
            if(board2[i][j] == 0)    continue;
            if(tilt[idx] == 0) {
                tilt[idx] = board2[i][j];
            }
            else if(tilt[idx] == board2[i][j]) {
                tilt[idx++] *= 2;
            }
            else {
                tilt[++idx] = board2[i][j];
            }
        }
        for(int j=0; j<n; j++) {
            board2[i][j] = tilt[j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    for(int tmp=0; tmp<1024; tmp++) {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                board2[i][j] = board[i][j];
        int brute = tmp;
        for(int i=0; i<5; i++) {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                mx = max(mx, board2[i][j]);
    }
    cout << mx;
}

