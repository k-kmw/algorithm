/* 9093 단어 뒤집기
 * 입력 반대의 순서로 출력 하는 경우 stack을 사용할 수 있다. */

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T;
    cin >> T;
    string str;
    stack<char> reverse; //문자를 저장하기 위한 스택

    cin.ignore(); //cin으로 int를 받으면 \n을 버퍼에서 안가져 오므로, 남아 있는 \n을 비우기 위해 버퍼를 비워 준다.
    for(int t=0; t<T; t++) {
        cin.ignore(); //
        //getline(cin, str);
        str += ' '; // 마지막 문자도 출력 하기 위해서 추가
        //cout << str;
        for(char & s : str) {
            if(s == ' ') {
                while(!reverse.empty()) {
                    cout << reverse.top();
                    reverse.pop();
                }
                cout << " ";
            }
            else {
                reverse.push(s);
            }
        }
    }
}