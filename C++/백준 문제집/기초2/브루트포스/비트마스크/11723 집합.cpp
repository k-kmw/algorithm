#include <bits/stdc++.h>
using namespace std;

int m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    int bits = 0;
//    cout << (bits & (1<<20)) << '\n';
    while(m--) {
        string cmd;
        cin >> cmd;
        int num;
        if(cmd == "add") {
            cin >> num;
            bits = bits | (1<<num);
        } else if(cmd == "remove") {
            cin >> num;
            bits &= ~(1<<num);
        } else if(cmd == "check") {
            cin >> num;
            if((bits & (1<<num)) != 0) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if(cmd == "toggle") {
            cin >> num;
            bits ^= 1<<num;
        } else if(cmd == "all") {
            bits = (1<<21) - 1;
        } else if(cmd == "empty") {
            bits = 0;
        }
    }
}