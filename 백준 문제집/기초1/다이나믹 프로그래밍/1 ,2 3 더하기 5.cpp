#include <bits/stdc++.h>
using namespace std;
int d[100001];
int tmp;
vector<int> vec;

int dfs(int k, int pre) {
    if(k == 1 || k == 2)    return 1;
    if(tmp == k) {
        for (const auto &v: vec) {
            cout << v << ' ';
        }
        cout << '\n';
        return 0;
    }
    int& ret = d[k];
    if(ret != 0)    return ret;
    for(int i=1; i<=3; i++) {
        if(pre == i) {
            continue;
        }
        if(tmp + i <= k) {
            tmp += i;
            vec.push_back(i);
            ret += 1 + dfs(i, pre) + dfs(k-i, i);
            vec.pop_back();
            tmp -= i;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fill(d, d+100001, 0);
        dfs(n, -1);
//        cout << d[n] << '\n';
    }
}