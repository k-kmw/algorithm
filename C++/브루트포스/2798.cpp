#include <bits/stdc++.h>
using namespace std;
int n, m;
int card[101];
bool vis[101];
int ans;

void choice(int k, int tmp) { // 한 장의 카드를 고른다.
    if(k == 3) {
        if(tmp <= m)
            ans = max(ans, tmp);
//        cout << tmp << '\n';
        return ;
    }
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            vis[i] = true;
            tmp += card[i];
            choice(k + 1, tmp);
            tmp -= card[i];
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> card[i];
    choice(0, 0);
    cout << ans << '\n';
}