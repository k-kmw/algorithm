#include <bits/stdc++.h>
using namespace std;

int n;
string board[30];
bool vis[30][30];
vector<int> ans;
int cnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void bfs(int i, int j) {
    queue< pair<int, int> > q;
    q.push(make_pair(i, j));
    vis[i][j] = true;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        cnt++;
        for(int dir=0; dir<4; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n)  continue;
            if(vis[ny][nx] || board[ny][nx] != '1') continue;
            q.push(make_pair(ny, nx));
            vis[ny][nx] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> board[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] != '1' || vis[i][j]) continue;
            bfs(i, j);
            ans.push_back(cnt);
            cnt = 0;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}