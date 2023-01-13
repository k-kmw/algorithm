#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T;
    cin >> T;
    string str;

    for(int t=0; t<T; t++) {
        stack<char> s;
        cin >> str;
        string out = "YES";
        for(const auto& c: str) {
            //cout << c << endl;
            if(c == '(')
                s.push(c);
            else if(c == ')') {
                if(s.empty()) {
                    out = "NO";
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty() && check != 1)
            cout << "NO" << endl;
    }
    return 0;
}
