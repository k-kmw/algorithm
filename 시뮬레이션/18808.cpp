#include <bits/stdc++.h>
using namespace std;
int board[40][40];
int sticker[10][10];
int rotateSticker[10][10];
int n, m, k;
int idx, idy;

bool isPossible(int a, int b) {
    if (a > n || b > m) return false;
    for(int i=0; i<=n-a; i++) {
        for (int j = 0; j <= m - b; j++) {
            bool possible = true;
            for (int g = i; g < i + a; g++) {
                for (int h = j; h < j + b; h++) {
                    if (board[g][h] == 1 && sticker[g - i][h - j] == 1) {
                        possible = false;
                        break;
                    }
                }
                if(!possible)   break;
            }
            if(possible) {
                idx = i;
                idy = j;
                return true;
            }
        }
    }
    return false;
}


void rotate(int a, int b) {
    for(auto & i : rotateSticker)
        fill(i, i+10, 0);

    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            rotateSticker[j][a-i-1] = sticker[i][j];
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while(k--) {
        for(auto & i : sticker)
            fill(i, i+10, 0);

        int a, b;
        cin >> a >> b;
        for(int i=0; i<a; i++)
            for(int j=0; j<b; j++)
                cin >> sticker[i][j];

        for(int dir=0; dir<4; dir++) {
            if(isPossible(a, b)) {
                for(int i=idx; i<idx+a; i++) {
                    for(int j=idy; j<idy+b; j++) {
                        if(sticker[i-idx][j-idy] == 1)
                            board[i][j] = sticker[i-idx][j-idy];
                    }
                }
                break;
            }
            else {
                rotate(a, b);
                swap(a, b);

                for(int i=0; i<10; i++) {
                    for (int j = 0; j < 10; j++) {
                        sticker[i][j] = rotateSticker[i][j];
                    }
                }
//                for(int i=0; i<a; i++) {
//                    for(int j=0; j<b; j++) {
//                        cout << sticker[i][j] << ' ';
//                    }
//                    cout << '\n';
//                }
//                cout << '\n';
            }
        }

//        for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) {
//                cout << board[i][j] << ' ';
//            }
//            cout << '\n';
//        }
//        cout << '\n';
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            if(board[i][j] == 1)
                ans++;
    }
    cout << ans;
}

