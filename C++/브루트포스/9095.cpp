#include <bits/stdc++.h>
using namespace std;
int n;
int tmp;
int cnt;

void dfs(int k) {
    if(tmp >= n) {
       if(tmp == n) {
           cnt++;
       }
       return;
    }
    for(int i=1; i<=3; i++) {
        tmp += i;
        dfs(k+1);
        tmp -= i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        dfs(0);
        cout << cnt << '\n';
        cnt = 0;
    }
    
}