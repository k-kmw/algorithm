#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[11][11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue< pair<int, int> > redQ;
    queue< pair<int, int> > blueQ;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                redQ.push(make_pair(i, j));
            }
            else if(board[i][j] == 'B') {
                blueQ.push(make_pair(i, j));
            }
        }
    }

    int t = 0;
    while(true) {
        t++;
        while(!redQ.empty()) {

        }
    }
}