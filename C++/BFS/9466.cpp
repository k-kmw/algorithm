#include <bits/stdc++.h>
using namespace std;

int board[100002];
int state[100002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fill(state+1, state+n+1, 0);
        for(int i=1; i<=n; i++)
            cin >> board[i];

        for(int i=1; i<=n; i++) {
            if(state[i] == 0) {
                int cur = i;
                while(true) {
                    state[cur] = i;
                    cur = board[cur];
                    if(state[cur] == i) { // cycle이 생성되면
                        while(state[cur] != -1) {
                            state[cur] = -1;
                            cur = board[cur];
                        }
                        break;
                    }
                    else if(state[cur] != 0)    break;
                }
            }
        }
        int cnt=0;
        for(int i=1; i<=n; i++)
            if(state[i] != -1)  cnt++;

        cout << cnt << '\n';
    }
}

// 답 보고 품
