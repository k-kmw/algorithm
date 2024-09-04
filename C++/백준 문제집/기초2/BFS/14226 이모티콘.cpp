#include <bits/stdc++.h>
using namespace std;
bool vis[10000][10000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 현재 화면에 있는 이모티콘 개수, 클립보드 개수와 시간을 연산에 맞게 큐에 넣으면서 bfs탐색
    // 2. 만약 s개가 되면 시간 출력 후 return
    int s;
    cin >> s;

    queue< pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(1, 0), 0)); // 초기 이모티콘 1개, 클립보드 개수 0, 시간 0
    vis[1][0] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int screen = cur.first.first;
        int clip = cur.first.second;
        int time = cur.second;
//        cout << screen << ' ' << clip << ' ' << time << '\n';
        if(screen == s) {
            cout << time << '\n';
            return 0;
        }
        if(!vis[screen][screen]) {
            q.push(make_pair(make_pair(screen, screen), time+1));
            vis[screen][screen] = true;
        }

        if(!vis[screen+clip][clip]) {
            q.push(make_pair(make_pair(screen+clip, clip), time+1));
            vis[screen+clip][clip] = true;
        }

        if(screen >= 1 && !vis[screen-1][clip]) {
            q.push(make_pair(make_pair(screen-1, clip), time+1));
            vis[screen-1][clip] = true;
        }
    }
}