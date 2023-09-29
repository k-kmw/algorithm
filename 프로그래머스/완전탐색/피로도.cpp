#include <bits/stdc++.h>
using namespace std;
// 던전마다 탐험을 시작하기 위해 필요한 최소 필요 피로도와 던전 탐험을 마쳤을 때 소모되는 소모 피로도
// 한 유저가 던전들을 최대한 많이 탐험
// 유저의 현재 피로도 k와 각 던전별 최소 [필요 피로도, 소모 피로도]가 담긴 2차원 배열 dungeons 매개변수, 유저가 텀험할수 있는 최대 던전 수 return
int answer = -1;
int cnt;
bool vis[10];
void dfs(int k, vector<vector<int>> dungeons) {
    answer = max(answer, cnt);
    for(int i=0; i<dungeons.size(); i++) {
        if(vis[i])  continue;
        if(k >= dungeons[i][0]) {
            cnt++;
            k -= dungeons[i][1];
            vis[i] = true;
            dfs(k, dungeons);
            cnt--;
            k += dungeons[i][1];
            vis[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    // 백트래킹하면서 모든 던전 방문하는 경우의 수 세기
    // 만약 피로도 조건을 충족하면 숫자를 더함
    // dungeons를 모두 탐색한 후, 총 더해진 숫자와 현재까지 최대값을 비교하여 갱신
    dfs(k, dungeons);
    return answer;
}