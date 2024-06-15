#include <bits/stdc++.h>
using namespace std;

bool vis[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if((a + b + c) % 3 != 0) {
        cout << 0;
        return 0;
    }
    // 1. 3개 중 2그룹을 고르기.
    // 2. 1번의 모든 경우에 대해 step을 진행하고 진행 결과를 큐에 넣기
    queue< pair< int, pair<int, int> > > q;
    q.push(make_pair(a, make_pair(b, c)));
    vis[a][b] = true;
    vis[a][c] = true;
    vis[b][c] = true;
    vis[b][a] = true;
    vis[c][a] = true;
    vis[c][b] = true;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int curA, curB, curC;
        curA = cur.first;
        curB = cur.second.first;
        curC = cur.second.second;

//        cout << curA << ' ' << curB << ' ' << curC << '\n';

        if(curA == curB && curB == curC) {
            cout << 1;
            return 0;
        }

        // a,b
        int mx = max(curA, curB);
        int mn = min(curA, curB);
        if(mx != mn) {
            mx -= mn;
            mn *= 2;
            if(mx <= 1000 && mn <= 1000 && !vis[mx][mn]) {
                vis[mx][mn] = true;
                vis[mn][mx] = true;
                q.push(make_pair(mn, make_pair(mx, curC)));
            }
        }

        // a, c
        mx = max(curA, curC);
        mn = min(curA, curC);
        if(mx != mn) {
            mx -= mn;
            mn *= 2;
            if(mx <= 1000 && mn <= 1000 && !vis[mx][mn]) {
                vis[mx][mn] = true;
                vis[mn][mx] = true;
                q.push(make_pair(mn, make_pair(curB, mx)));
            }
        }

        // b, c
        mx = max(curC, curB);
        mn = min(curC, curB);
        if(mx != mn) {
            mx -= mn;
            mn *= 2;
            if(mx <= 1000 && mn <= 1000 && !vis[mx][mn]) {
                vis[mx][mn] = true;
                vis[mn][mx] = true;
                q.push(make_pair(curA, make_pair(mn, mx)));
            }
        }
    }
    cout << 0;
}