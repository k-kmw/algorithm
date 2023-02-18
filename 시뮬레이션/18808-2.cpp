#include <bits/stdc++.h>
using namespace std;
int board[40][40];
int sticker[10][10];
int n, m, k;
int r, c;

bool pastable(int x, int y) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(board[x+i][y+j] == 1 && sticker[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void paste(int x, int y) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(sticker[i][j] == 1)
                board[x+i][y+j] = sticker[i][j];
        }
    }
}

void rotate() {
    int tmp[10][10] = {0,};
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            tmp[j][r-1-i] = sticker[i][j];
        }
    }

    swap(r, c);

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            sticker[i][j] = tmp[i][j];
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while(k--) {
        cin >> r >> c;

        for(int i=0; i<10; i++)
            fill(sticker[i], sticker[i]+10, 0);

        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cin >> sticker[i][j];

        for(int rot=0; rot<4; rot++) {
            bool isPaste = false;

            for(int i=0; i<=n-r; i++) {
                for(int j=0; j<=m-c; j++) {
                    if(pastable(i, j)) {
                        isPaste = true;
                        paste(i, j);
                        break;
                    }
                }
                if(isPaste)
                    break;
            }

            if(isPaste)
                break;
            rotate();
        }
//        for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) {
//                cout << board[i][j] << ' ';
//            }
//            cout << '\n';
//        }
//        cout << '\n';
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 1)
                ans++;
        }
    }
    cout << ans;
}

