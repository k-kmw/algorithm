#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

void parse(string& tmp, deque<int>& d){
    int cur = 0;
    for(int i=1; i+1<tmp.size(); i++) { // 첫 번째 괄호, 마지막 괄호 제외
        if(tmp[i] == ',') {
            d.push_back(cur);
            cur = 0;
        }
        else {
            cur = 10*cur + tmp[i]-'0'; // 두 자리수와 100까지 고려
        }
    }
    if(cur != 0)    d.push_back(cur);
}

void print_result(deque<int>& d){
    cout << '[';
    for(int i=0; i<d.size(); i++) {
        cout << d[i];
        if(i+1 != d.size()) // 마지막 숫자가 아닌 경우만 , 출력
            cout << ',';
    }
    cout << "]\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string op, str;
        int n;
        int rev = 0; // reverse인지 확인
        bool isWrong = false; // error 출력시 print_result 호출 하지 않음
        deque<int> dq; // 입력 읽기전 문제만 읽고 queue로 풀이 가능하다고 생각하였지만 reverse함수가 없어서 dequeue선택,
        // but reverse 사용하면 시간초과 뜸 n^2이라서,
        // 따라서 flag써서 양쪽 다 pop 할 수 있는 dequeue를 사용하는 것이 더 타당함
        cin >> op >> n >> str;
        parse(str, dq);
        for(auto c : op) {
            if(c == 'R') {
                rev = 1-rev;
            }
            else { // D인 경우
                if(dq.empty()) { // 비었는데 D하는 경우
                    cout << "error\n";
                    isWrong = true;
                    break;
                }
                else {
                    if(rev) dq.pop_back(); // reverse일 경우 뒤에서 제거
                    else    dq.pop_front(); // 아닐 경우 앞에서 제거
                }
            }
        }
        if(rev) // reverse일 경우 출력전 뒤집은 후 출력
            // 순서 뒤집고 맨 앞 제거 하는 것과, 맨 뒤 원소 제거 하고 순서 뒤집는 것은 같음
            reverse(dq.begin(), dq.end());
        if(!isWrong)
            print_result(dq);
    }
}