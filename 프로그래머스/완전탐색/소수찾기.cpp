#include <bits/stdc++.h>
using namespace std;
// 각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return
// n = 7

int answer = 0;
string num;
bool vis[8];
set<int> numset;
// 2 3 5 7 11
bool isPrime() {
    // cout << num << '\n';
    int num2 = stoi(num);
    if(num2 <= 1)   return false;
    for(int i=2; i*i<=num2; i++) {
        if(num2 % i == 0)   return false;
    }
    return true;
}

// step 하나 당 하나의 문자 결정
// 각 step마다 소수인지 확인
void dfs(string numbers) {
    // cout << num << '\n';
    if(!num.empty() && isPrime()) {
        numset.insert(stoi(num));
    }
    for(int i=0; i<numbers.size(); i++) {
        if(vis[i])  continue;
        num += numbers[i];
        vis[i] = true;
        dfs(numbers);
        vis[i] = false;
        num.pop_back();
    }
}


int solution(string numbers) {
    // 1. 문자열을 입력받는다
    // 2. 입력받은 문자열에서 dfs를 이용하여 step 하나 당 하나의 문자 결정
    // 3. 각 step마다 소수인지 확인
    dfs(numbers);
    answer = numset.size();
    return answer;
}