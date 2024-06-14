#include <bits/stdc++.h>
using namespace std;

bool vis[101];
int n, m;
int snake[101]; // index:value = 현재 위치:이동할 위치
int ladder[101]; // index:value = 현재 위치:이동할 위치
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int cur, next;
        cin >> cur >> next;
        ladder[cur] = next;
    }
    for(int j=0; j<m; j++) {
        int cur, next;
        cin >> cur >> next;
        snake[cur] = next;
    }

    queue< pair<int, int> > q; // 번호, 개수
    vis[1] = true;
    q.push(make_pair(1, 0));
    int mn = INT_MAX;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int num = cur.first;
        int cnt = cur.second;
        if(num == 100) {
            mn = min(mn, cnt);
            break;
        }
        for(int i=1; i<=6; i++) {
            if(num+i > 100) break;
            if(vis[num+i]) continue;
            vis[num+i] = true;
            if(snake[num+i] != 0) {
                vis[snake[num+i]] = true;
                q.push(make_pair(snake[num+i], cnt+1));
            } else if(ladder[num+i] != 0) {
                vis[ladder[num+i]] = true;
                q.push(make_pair(ladder[num+i], cnt+1));
            } else {
                q.push(make_pair(num+i, cnt+1));
            }
        }
    }
    cout << mn;
}