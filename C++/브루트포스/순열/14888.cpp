#include<bits/stdc++.h>
using namespace std;
// 연산자 끼워넣가
// N개의 수로 이루어진 수열 A1~An
// 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자. +, -, *, /
// 식의 계산은 연산자 우선순위를 무시하고 앞에서부터 진행
// 나눗셈은 정수 나눗셈으로 몫만 취함
// N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과의 최대/최소를 구함

int nums[12];
int opNums[4]; // 연산자의 개수 저장
int n;
vector<char> ops; // 연산자 경우의 수 저장
char op[] = {'+', '-', '*', '/'}; // 연산자 매핑
long long mx = -1000000000;
long long mn = 1000000000;

void update() {
//    for(int i=0; i<ops.size(); i++) {
//        cout << ops[i] << ' ';
//    }
//    cout << '\n';

    long long tmp = nums[0];
    for(int i=0; i<n-1; i++) {
        if(ops[i] == '+') {
            tmp += nums[i+1];
        }
        else if(ops[i] == '-') {
            tmp -= nums[i+1];
        }
        else if(ops[i] == '*') {
            tmp *= nums[i+1];
        }
        else {
            tmp /= nums[i+1];
        }
    }
    mx = max(mx, tmp);
    mn = min(mn, tmp);
}


// k번째 연산자를 결정
void dfs(int k) {
    if(k == n-1) { // n-1개의 연산자를 결정하면 최대 최소 확인
        update();
        return;
    }

    for(int i=0; i<4; i++) {
        if(opNums[i] == 0) continue;
        ops.push_back(op[i]);
        opNums[i]--;
        dfs(k+1);
        ops.pop_back();
        opNums[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    for(int i=0; i<4; i++) {
        cin >> opNums[i];
    }
    dfs(0);
    cout << mx << '\n';
    cout << mn;
    // 1. n개의 숫자의 입력과 n-1개의 연산자 정보를 입력받는다
    // 2. 모든 연산자의 경우의 수를 구한다.
    // 3. 구한 연산자의 순서마다 최대값과 최소값을 갱신한다.
}