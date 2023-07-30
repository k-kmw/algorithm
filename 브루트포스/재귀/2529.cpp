#include <bits/stdc++.h>
using namespace std;
int n;
char cmps[10];
bool vis[10];
string mx = "0";
string mn = "9999999999";
vector<int> nums;

void update() {
    bool check = true; // 숫자들이 부등호를 만족할 경우 true
    int idx = 0;
    while(idx < n) { // 숫자들과 부등호가 일치하는지 검사
        if(cmps[idx] == '<') {
            if(nums[idx] > nums[idx+1]) {
                check = false;
            }
        }
        else {
            if(nums[idx] < nums[idx+1]) {
                check = false;
            }
        }
        idx++;
    }
    if(check) { //만족할 경우 최대값, 최소값을 갱신
        string s;
        for(int num : nums) {
            s += to_string(num);
        }
        if(s < mn) {
            mn = s;
        }
        if(s > mx) {
            mx = s;
        }
    }
}

void dfs(int k) {
    if(k == n+1) {
        update();
        return;
    }
    for(int i=0; i<=9; i++) {
        if(vis[i]) continue;
        vis[i] = true;
        nums.push_back(i);
        dfs(k+1);
        vis[i] = false;
        nums.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)  cin >> cmps[i];
    dfs(0); // 들어갈 수 있는 숫자의 모든 경우의 수를 구함
    cout << mx << '\n';
    cout << mn << '\n';
}