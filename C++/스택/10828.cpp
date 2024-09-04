#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int n;
    cin >> n;
    while(n--) {
        string op;
        cin >> op;
        if(op == "push") {
            int a;
            cin >> a;
            s.push(a);
        }
        else if(op == "top") {
            if(!s.empty())
                cout << s.top() << '\n';
            else {
                cout << -1 << '\n';
            }
        }
        else if(op == "size") {
            cout << s.size() << '\n';
        }
        else if(op == "pop") {
            if(!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if(op == "empty") {
            if(s.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}