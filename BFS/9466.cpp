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
        int no_team = 0;
        queue<int> q;
        for(int i=1; i<=n; i++)
            cin >> board[i];

        q.push(1);
        vis[1] = true;
        int idx = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            int nx = board[cur];
            if(nx == cur || board[nx] == cur || vis[nx])   {
                vis[nx] = true;
                nx = ++idx;
            }
            q.push(nx);
            vis[nx] = true;
        }
    }

}

// 못품


