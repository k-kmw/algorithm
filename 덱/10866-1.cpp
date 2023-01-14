#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x) {
    dat[--head] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

void pop_front() {
    head++;
}

void pop_back() {
    tail--;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

int size() {
    return tail-head;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        string op;
        cin >> op;
        if(op == "push_front") {
            int a;
            cin >> a;
            push_front(a);
        }
        else if(op =="push_back") {
            int a;
            cin >> a;
            push_back(a);
        }
        else if(op == "pop_front") {
            if(head == tail)   cout << "-1" <<'\n';
            else {
                cout << front() << '\n';
                pop_front();
            }
        }
        else if(op == "pop_back") {
            if(head == tail)   cout << "-1" << '\n';
            else {
                cout << back() << '\n';
                pop_back();
            }
        }
        else if(op == "size") {
            cout << size() << '\n';
        }
        else if(op == "empty") {
            cout << int(head == tail) << '\n';
        }
        else if(op == "front") {
            if(head == tail)   cout << "-1" << '\n';
            else {
                cout << front() << '\n';
            }
        }
        else {
            if(head == tail)   cout << "-1" << '\n';
            else {
                cout << back() << '\n';
            }
        }
    }
}