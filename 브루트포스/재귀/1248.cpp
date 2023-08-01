#include <bits/stdc++.h>
using namespace std;
int n;
char s[11][11];
vector<int> nums;

bool check(int idx) {
    for(int i=0; i<idx; i++) {
        int sum = accumulate(nums.begin() + i, nums.begin() + idx + 1, 0);
        if(s[i][idx] == '-' && sum >= 0) {
            return false;
        }
        else if(s[i][idx] == '+' && sum <= 0) {
            return false;
        }
        else if(s[i][idx] == '0' && sum != 0) {
            return false;
        }
    }
    return true;
}

void dfs(int k) {
    if(k == n) {
        for (const auto &num: nums) {
            cout << num << ' ';
        }
        cout << '\n';
        exit(0);
    }

    int st;
    int en;
    if(s[k][k] == '0') {
        nums.push_back(0);
        if(check(k))
            dfs(k+1);
        nums.pop_back();
    }
    else if(s[k][k] == '+') {
        st = 1;
        en = 10;
    }
    else if(s[k][k] == '-'){
        st = -10;
        en = -1;
    }

    for(int i=st; i<=en; i++) {
        nums.push_back(i);
        if(check(k))
            dfs(k+1);
        nums.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            cin >> s[i][j];

    dfs(0);
}