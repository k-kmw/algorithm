#include <bits/stdc++.h>
using namespace std;

// 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할
// 두 전력망이 갖게 되는 송전탑의 개수를 최대한 비슷하게
// 송전탑의 개수 n(2~100), 전선 정보 wires [v1, v2]
// 두 전력망이 가지고 있는 송전탑 개수의 차이를 return
bool vis[101];
int cnt;
int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    // wires를 순회하며 하나를 끊고 개수를 비교. cnt - (n-cnt) = 2*cnt - n
    queue<int> q;
    for(int i=0; i<wires.size(); i++) {
        cnt = 0;
        fill(vis, vis+101, 0);
        vis[wires[i][1]] = true;
        q.push(wires[i][0]);
        vis[wires[i][0]] = true;
        while(!q.empty()) {
            int cur = q.front();
            // cout << i << ' ' << cur << '\n';
            q.pop();
            cnt++;
            for(int i=0; i<wires.size(); i++) {
                if(wires[i][0] == cur && !vis[wires[i][1]]) {
                    q.push(wires[i][1]);
                    vis[wires[i][1]] = true;
                }

                if(wires[i][1] == cur && !vis[wires[i][0]]) {
                    q.push(wires[i][0]);
                    vis[wires[i][0]] = true;
                }
            }
        }
        // cout << cnt << '\n';
        answer = min(answer, abs(2*cnt - n));
    }
    return answer;
}