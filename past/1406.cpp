#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    string str;
    int n;
    stack<char> left;
    stack<char> right;
    cin >> str;
    cin >> n;

    /*for(int i=str.length(); i>0; i--) {
        //cout << str.length() << endl;
        left.push(str[i-1]);
    }*/
    for(const auto& c : str) {
        left.push(c);
    }

    char cmd;
    char tmp;
    for(int i=0; i<n; i++) {
        cin >> cmd;
        switch(cmd) {
            case 'P': {
                char c;
                cin >> c;
                left.push(c);
                break;
            }
            case 'L':
                if(!left.empty()) {
                    right.push(left.top());
                    left.pop();
                    /*tmp = left.top();
                    left.pop();
                    right.push(tmp);*/
                }
                break;

            case 'D': {
                if(!right.empty()) {
                    left.push(right.top());
                    right.pop();
                    /*tmp = right.top();
                    right.pop();
                    left.push(tmp);*/
                }
                break;
            }
            case 'B':
                if(!left.empty())
                    left.pop();
                break;

            default:
                break;
        }
    }
    while(!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()) {
        cout << right.top();
        right.pop();
    }
    return 0;
}