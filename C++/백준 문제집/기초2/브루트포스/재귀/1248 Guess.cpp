#include <bits/stdc++.h>
using namespace std;
char board[11][11];
vector<int> nums;
int n;

// k번째 숫자를 결정
void dfs(int k) {

    for(int i=0; i<k; i++) {
        int sum = 0;
        int idx = i;
        for(int j=i; j<k; j++) {
            sum += nums[idx];
            idx++;
            if(board[i][j] == '+' && sum <= 0)  return;
            if(board[i][j] == '-' && sum >= 0)  return;
            if(board[i][j] == '0' && sum != 0)  return;
        }
    }

    if(k == n) {
        for (const auto &item: nums) {
            cout << item << ' ';
        }
        exit(0);
    }

    if(board[k][k] == '-') { // 음수이면
        for(int i=-10; i<=-1; i++) {
            nums.push_back(i);
            dfs(k+1);
            nums.pop_back();
        }
    } else if(board[k][k] == '+') {// 양수이면
        for(int i=1; i<=10; i++) {
            nums.push_back(i);
            dfs(k+1);
            nums.pop_back();
        }
    } else { // 0이면
        nums.push_back(0);
        dfs(k+1);
        nums.pop_back();
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            cin >> board[i][j];
        }
    }
    // 1. s[i][i]를 확인해서 음수, 0, 양수 판별
    // 2. 음수이면 -10 ~ -1, 양수이면 1~10을 범위로 dfs(k) + backtracking
    // 3. k == n 일 때 가능한 경우이면 출력

    dfs(0);
}