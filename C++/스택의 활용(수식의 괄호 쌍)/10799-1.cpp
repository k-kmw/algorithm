#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;
    string str;
    cin >> str;
    unsigned int total = 0;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(') { // 여는 괄호이면 push
            s.push(str[i]);
        }
        else {
            if(str[i-1] == '(') { // 레이저이면
                s.pop(); // 막대 시작인줄 알고 넣었므로 pop
                total += s.size(); // 레이저이면 스택의 크기만큼 더해줌(여는 괄호 개수)
            }
            else {
                s.pop();
                total += 1; // 레이저가 아니고 닫힌 괄호이면 막대가 끊기므로 1을 더해줌
            }
        }
    }
    cout << total;
}
