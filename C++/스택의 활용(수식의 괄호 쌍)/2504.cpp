#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;
    string str;
    cin >> str;

    // 분배 법칙을 이용
    int sum=0;
    int mul=1;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(') { // str[i] == '('
            s.push(str[i]);
            mul *= 2;
        }
        else if(str[i] == '[') { // str[i] == '['
            s.push(str[i]);
            mul *= 3;
        }
        else if(str[i] == ')') { // str[i] == ')'
            if(s.empty() || s.top() != '(') {
                sum = 0;
                break;
            }
            if(str[i-1] == '(') sum += mul;
            s.pop();
            mul /= 2;
        }
        else { // str[i] == ']'
            if(s.empty() || s.top() != '[') {
                sum = 0;
                break;
            }
            if(str[i-1] == '[') sum += mul;
            s.pop();
            mul /= 3;
        }
    }
    if(!s.empty())  sum = 0;
    cout << sum;
}
