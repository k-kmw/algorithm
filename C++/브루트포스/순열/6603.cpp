#include <bits/stdc++.h>
using namespace std;
int n = 1;
int s[13];
vector<int> lotto;

void dfs(int k, int st) {
    if(k == 6) {
        for (const auto &item: lotto) {
            cout << item << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=st; i<n; i++) {
        lotto.push_back(s[i]);
        dfs(k+1, i+1);
        lotto.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(n != 0) {
        cin >> n;
        for(int i=0; i<n; i++)  cin >> s[i];
        dfs(0, 0);
        cout << '\n';
    }
}