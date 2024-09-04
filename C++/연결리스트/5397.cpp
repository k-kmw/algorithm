#include <iostream>
using namespace std;
const int MX = 1000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void insert(int addr, char c) { // addr 뒤에 삽입
    dat[unused] = c;
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
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unused = 1;
    int t;
    cin >> t;
    while(t--) {
        int cur = 0;

        fill(pre, pre+MX, -1);
        fill(nxt, nxt+MX, -1);
        string s;
        cin >> s;
        for(auto c : s) {
            if(c == '<') {
                if(pre[cur] != -1)
                    cur = pre[cur];
            }
            else if(c == '>') {
                if(nxt[cur] != -1)
                    cur = nxt[cur];
            }
            else if(c == '-') {
                if(cur != 0) {
                    erase(cur);
                    cur = pre[cur];
                }
            }
            else {
                insert(cur, c);
                cur = nxt[cur];
            }
        }
        traverse();
    }
}