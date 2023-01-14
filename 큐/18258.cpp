#include <iostream>
using namespace std;
const int MX = 2000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
    dat[tail++] = x;
}

void pop() {
    head++;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

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
            if(head == tail) {
                cout << "-1" << '\n';
            }
            else {
                cout << front() << '\n';
                pop();
            }
        }
        else if(op == "size")   cout << tail-head << '\n';
        else if(op == "empty")  cout << int(head == tail) << '\n';
        else if(op == "front")  {
            if(head == tail)   cout << "-1" << '\n';
            else {
                cout << front() << '\n';
            }
        }
        else {
            if(head== tail)   cout << "-1" << '\n';
            else
                cout << back() << '\n';
        }
    }

}