#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//int board[100002];
int dist[100002];
int dx[2] = {-1, 1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    fill(dist, dist+100002, -1);

    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int nx : {cur-1, cur+1, cur*2}) {
            if(nx < 0 || nx > 100000 || dist[nx] != -1)  continue;
            if(nx == k) {
                cout << dist[cur]+1;
                return 0;
            }
            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }
    cout << '0';
}


