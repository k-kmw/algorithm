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
        int check = 0;
        for(const auto& c: str) {
            //cout << c << endl;
            if(c == '(')
                s.push(c);
            else if(c == ')') {
                if(s.empty()) {
                    cout << "NO" << endl;
                    check = 1;
                    break;
                }
                s.pop();
            }
        }
        if(s.empty() && check != 1)
            cout << "YES" << endl;
        else if(!s.empty() && check != 1)
            cout << "NO" << endl;
    }
    return 0;
}


/*switch(c) {
    case '(':
        s.push(c);
        break;
    case ')': {
        if(s.empty()) {
            cout << "NO" << endl;
            check = 1;
            break;
        }
        s.pop();
    }
}*/