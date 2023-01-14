#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> d;
    int n;
    cin >> n;
    while(n--) {
        string op;
        cin >> op;
        if(op == "push_front") {
            int a;
            cin >> a;
            d.push_front(a);
        }
        else if(op =="push_back") {
            int a;
            cin >> a;
            d.push_back(a);
        }
        else if(op == "pop_front") {
            if(d.empty())   cout << "-1" <<'\n';
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if(op == "pop_back") {
            if(d.empty())   cout << "-1" << '\n';
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if(op == "size") {
            cout << d.size() << '\n';
        }
        else if(op == "empty") {
            cout << int(d.empty()) << '\n';
        }
        else if(op == "front") {
            if(d.empty())   cout << "-1" << '\n';
            else {
                cout << d.front() << '\n';
            }
        }
        else {
            if(d.empty())   cout << "-1" << '\n';
            else {
                cout << d.back() << '\n';
            }
        }
    }
}