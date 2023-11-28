#include<bits/stdc++.h>
using namespace std;
bool vis[101][101];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first.second + dx[dir];
            int ny = cur.first.first + dy[dir];
            int cnt = cur.second;
            // cout << cnt << '\n';
            if (ny < 0 || nx < 0 || nx >= m || ny >= n)  continue;
            if (vis[ny][nx] || maps[ny][nx] == 0)    continue;
            if (ny == n-1 && nx == m-1) return cnt+1;
            vis[ny][nx] = true;
            q.push({{ny, nx}, cnt+1});
        }
    }
    return answer;
}