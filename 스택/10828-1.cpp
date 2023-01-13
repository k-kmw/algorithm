#include <iostream>
using namespace std;
const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

void pop() {
    pos--;
}

int top() {
    return dat[pos-1];
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        string op;
        cin >> op;
        if(op == "push") {
            int a;
            cin >> a;
            push(a);
        }
        else if(op == "pop") {
            if(pos != 0) {
                cout << top() << '\n';
                pop();
            }
            else {
                cout << "-1" << '\n';
            }
        }
        else if(op == "size") {
            cout << pos << '\n';
        }
        else if(op == "empty") {
            if(pos == 0) {
                cout << 1 << '\n';
            }
            else
                cout << '0' << '\n';
        }
        else {
            if(pos != 0) {
                cout << top() << '\n';
            }
            else {
                cout << "-1" << '\n';
            }
        }
    }
}