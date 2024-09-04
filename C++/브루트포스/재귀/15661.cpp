#include <bits/stdc++.h>
using namespace std;
int n;
int s[21][21];
int ans = 100*200;
bool hasTeam[21];

int getDist() {
    int t1Score = 0;
    int t2Score = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(hasTeam[i] && hasTeam[j])    t1Score += s[i][j];
            if(!hasTeam[i] && !hasTeam[j])    t2Score += s[i][j];
        }
    }
    return abs(t1Score - t2Score);
}

void dfs(int k, int st) {
    if(k > n/2)  return; // 전체 인원의 절반까지만 경우의 수를 구하면, 나머지는 자동으로 한 팀이므로 모든 경우의 수 탐색과 동일
    ans = min(ans, getDist()); // 구한 조합에 대하여 팀의 능력치 차이를 구함
    for(int i=st; i<=n; i++) {
        hasTeam[i] = true;
        dfs(k+1, i+1);
        hasTeam[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> s[i][j];

    // dfs로 모든 가능한 팀의 조합을 구함
    dfs(0, 1);
    cout << ans;
}