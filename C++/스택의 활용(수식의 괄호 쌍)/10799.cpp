#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;
    string str;
    cin >> str;
    int total = 0;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(') {
            if(str[i+1] == ')') {
                if(!s.empty())
                    total += s.size();
            }
            else {
                s.push(str[i]);
                total++;
            }
        }
        else {
            if(i != 0 && str[i-1] != '(') {
                s.pop();
            }
        }
    }
    cout << total;
}
