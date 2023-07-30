#include <bits/stdc++.h>
using namespace std;
int n;
int t[16];
int p[16];
vector<int> days;
int ans;

void dfs(int st) {
    if(st > n+1) { // 새로운 시작점이 n+1보다 크면 범위를 벗어남
        return;
    }

    int tmp = 0;
    for (const auto &day: days) { // 지금까지 추가된 날의 페이를 더함
        tmp += p[day];
    }
    ans = max(ans, tmp);

    for(int i=st; i<=n; i++) {
        days.push_back(i);
        dfs(i+t[i]); // 다음 가능한 일자로 넘어감
        days.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)  cin >> t[i] >> p[i];

    dfs(1);
    cout << ans;
}