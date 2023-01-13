#include <iostream>
using namespace std;

int q[10000];
int front=0;
int rear=0;

void push() {
    int item;
    cin >> item;
    q[rear++] = item;
}

int pop() {
    if(front != rear)
        return q[front++];
    else
        return -1;
}

int size() {
    return rear-front;
}

int empty() {
    if(front == rear)   return 1;
    else    return 0;
}

int frontf() {
    if(front != rear)
        return q[front];
    else
        return -1;
}

int back() {
    if(front != rear)
        return q[rear-1];
    else
        return -1;
}


int main() {
    int n;
    string cmd;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> cmd;
        if(cmd == "push")
            push();
        else if(cmd == "front")
            cout << frontf() << endl;
        else if(cmd == "pop")
            cout << pop() << endl;
        else if(cmd == "size")
            cout << size() << endl;
        else if(cmd == "empty")
            cout << empty() << endl;
        else if(cmd == "back")
            cout << back() << endl;
    }
    return 0;
}