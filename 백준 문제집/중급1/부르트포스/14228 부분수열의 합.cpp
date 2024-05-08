#include <bits/stdc++.h>
using namespace std;

int n;
int s[25];
bool res[2000005];

void dfs(int k, int sum) {
    //cout << k << ' ' << sum << '\n';
    res[sum] = true;
    if(k == n)  return;
    dfs(k+1, sum+s[k]);
    dfs(k+1, sum);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // 1. 더하는 경우와 더하지 않는 경우 모두 고려
    // 1. 매 호출마다 숫자를 배열에 표시
    dfs(0, 0);
    for (int i = 1; i <= 2000005; i++) {
        if (!res[i]) {
            cout << i << '\n';
            break;
        }
    }
}