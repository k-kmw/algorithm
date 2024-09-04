#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

string board[101];
int dist[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> board[i];
    }
    for(int i=0; i<N; i++)
        fill(dist[i], dist[i]+M, -1);

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M)  continue;
            if(dist[nx][ny] != -1 || board[nx][ny] == '0') continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
//    for(int i=0; i<N; i++) {
//        for (int j = 0; j < M; j++)
//            cout << dist[i][j] << ' ';
//        cout << '\n';
//    }
    cout << dist[N-1][M-1]+1;
}