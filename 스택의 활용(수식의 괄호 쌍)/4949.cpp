#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    getline(cin, line);
    while(line[0] != '.') {
        stack<char> s;
        string ans = "yes";
        for(auto c : line) {
            if(c == '[' || c == '(')
                s.push(c);

            else if(c == ')') {
                if(s.empty() || s.top() != '(') {
                    ans = "no";
                    break;
                }
                s.pop();
            }
            else if(c == ']') {
                if(s.empty() || s.top() != '[') {
                    ans = "no";
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty())  ans = "no";
        cout << ans << '\n';
        getline(cin, line);
    }
}
