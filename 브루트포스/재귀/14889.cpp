#include <bits/stdc++.h>
using namespace std;
int n;
int s[21][21];
int ans = 100*200;
vector<int> t1;
bool hasTeam[21];

int getDist() {
    vector<int> t2;
    int t1Score = 0;
    int t2Score = 0;
    for(int i=1; i<=n; i++) {
        if(!hasTeam[i])
            t2.push_back(i);
    }
    for(int i=0; i<t1.size(); i++) {
        for(int j=i+1; j<t1.size(); j++) {
            t1Score += s[t1[i]][t1[j]] + s[t1[j]][t1[i]];
            t2Score += s[t2[i]][t2[j]] + s[t2[j]][t2[i]];
        }
    }
    return abs(t1Score - t2Score);
}

void dfs(int k, int st) {
    if(k == n/2) {
        ans = min(ans, getDist()); // 구한 조합에 대하여 팀의 능력치 차이를 구함
        return;
    }
    for(int i=st; i<=n; i++) {
        hasTeam[i] = true;
        t1.push_back(i);
        dfs(k+1, i+1);
        hasTeam[i] = false;
        t1.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> s[i][j];

    // dfs로 n/2의 팀 조합을 구함
    dfs(0, 1);
    cout << ans;
}