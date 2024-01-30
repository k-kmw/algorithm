#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001];
int sorted_a[10001];
bool vis[10001];
vector<int> vec;
bool isFind;
bool isPrint;
bool en;

void dfs(int k) {
    if(k == n) {;
        if(isFind) {
            for (const auto &v: vec) {
                cout << v << ' ';
            }
            isPrint = true;
        }
        else {
            bool check = true;
            for(int i=0; i<n; i++) {
                if(a[i] != vec[i]) {
                    check = false;
                    break;
                }
            }
            if(check) {
                isFind = true;
            }
        }
        return;
    }

    for(int i=0; i<n; i++) {
        if(vis[i])  continue;
        vec.push_back(sorted_a[i]);
        vis[i] = true;
        dfs(k+1);
        if(isPrint) {
            en = true;
            return;
        }
        vec.pop_back();
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }
    sort(sorted_a, sorted_a + n);
    dfs(0);
    if(!en) {
        cout << -1 << '\n';
    }
}

// 시간 초과
// 억지로 끼워 맞춰서 품
// dfs 호출 횟수 n!
// 각 dfs 호출 내에서 k != n 일 때, 10^4번 for문 반복
// k == n 이면 10^4.