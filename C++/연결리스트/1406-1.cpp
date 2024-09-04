#include <iostream>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void insert(int addr, int num) {
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
    int cur = nxt[0];
    while(cur != -1) {
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.fill(0);

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    string s;
    int m;
    cin >> s >> m;
    int cur = 0;
    for(auto c : s) {
        insert(cur, c);
        cur++;
    }

    while(m--) {
        char op;
        cin >> op;
        if(op == 'P') {
            char add;
            cin >> add;
            insert(cur, add);
            cur = nxt[cur];
        }
        else if(op == 'L') {
            if(pre[cur] != -1)  cur = pre[cur];
        }
        else if(op == 'D') {
            if(nxt[cur] != -1)  cur = nxt[cur];
        }
        else {
            if(cur != 0) {
                erase(cur);
                cur = pre[cur];
            }
        }
    }
    traverse();
}
