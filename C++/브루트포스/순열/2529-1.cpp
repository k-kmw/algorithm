#include <bits/stdc++.h>
using namespace std;
// 두 종류의 부등호 기호 <와 >가 k개 나열된 순서열 A
// 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자(0~9)를 넣어서 모든 부등호 관계를 만족
// 부등호 관계를 만족시키는 정수중 최대값과 최솟값을 찾기

// 1. step마다 하나의 숫자를 결정
// 2. 숫자가 k+1개가 되면 부등호를 만족하는지 조사하고, 최대/최소값을 갱신
int n;
string op;
bool vis[10];
string num;
vector<string> ans;

bool check() { // 부등호를 만족하는지 검사
    for(int i=0; i<op.size(); i++) {
        if(op[i] == '<') {
            if(num[i] > num[i+1])   return false;
        }
        else {
            if(num[i] < num[i+1])   return false;
        }
    }
    return true;
}

void dfs(int k) {
    if(k==n+1) {
        if(check()) {
            ans.push_back(num);
        }
        return;
    }
    for(int i=0; i<=9; i++) {
        if(vis[i]) continue;
        num += to_string(i);
        vis[i] = true;
        dfs(k+1);
        num.pop_back();
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        char c;
        cin >> c;
        op += c;
    }
    dfs(0);
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second << '\n';
    cout << *p.first << '\n';
    // k+1자리 숫자를 생성하고 부등호 만족하는지 조사
    // 최소값 최대값 갱신
}

// 정수 <-> 문자열 +- '0'을 함으로써 변환가능

// 문자열 숫자 비교
// 원리: 앞에서부터 하나의 숫자씩 비교
// 같은 길이의 문자열 숫자는 비교가 가능
// 다른 길이의 문자열 숫자는 비교가 불가능

// minmax_element를 이용하여 문자열의 최소 최대값을 쉽게 구할 수 있다.

//    string v1 = "9";
//    string v2 = "12";
//    cout << (v1 < v2) << '\n';
//    cout << ("9" < "12");
// 두 개의 결과가 다른 이유를 모르겠음.
