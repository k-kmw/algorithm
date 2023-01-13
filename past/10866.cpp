#include <iostream>
using namespace std;

int d[10000];
int head=5000;
int tail=5001;

int empty() {
    if(head == tail-1)
        return 1;
    else
        return 0;
}

void push_front() {
    int x;
    cin >> x;
    if(head >= 0)
        d[head--] = x;
}

void push_back() {
    int x;
    cin >> x;
    if(tail <= 10000)
        d[tail++] = x;
}

int pop_front() {
    if(!empty())
        return d[++head];
    else
        return -1;
}

int pop_back() {
    if(!empty())
        return d[--tail];
    else
        return -1;
}

int size() {
    if(empty())
        return 0;
    else
        return tail-head-1;
}

int front() {
    if(!empty())
        return d[head+1];
    else
        return -1;
}

int back() {
    if(!empty())
        return d[tail-1];
    else
        return -1;
}

int main() {
    int n;
    string cmd;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> cmd;
        if(cmd == "push_front")
            push_front();
        else if(cmd == "push_back")
            push_back();
        else if(cmd == "pop_front")
            cout << pop_front() << endl;
        else if(cmd == "pop_back")
            cout << pop_back() << endl;
        else if(cmd == "size")
            cout << size() << endl;
        else if(cmd == "front")
            cout << front() << endl;
        else if(cmd == "back")
            cout << back() << endl;
        else if(cmd == "empty")
            cout << empty() << endl;
    }

    return 0;
}