#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> l;
    string s;
    int m;
    char cmd;
    cin >> s >> m;
    for(char c:s) {
        l.push_back(c);
    }
    auto iter = l.end();

    for(int i=0; i<m; i++) {
        cin >> cmd;
        if(cmd == 'P') {
            char a;
            cin >> a;
            l.insert(iter, a);
        }
        if(cmd == 'L') {
            if(iter != l.begin())   iter--;
        }
        if(cmd == 'D') {
            if(iter != l.end()) iter++;
        }
        if(cmd == 'B') {
            if(iter != l.begin()) {
                iter--;
                iter = l.erase(iter);
            }
        }
    }
    for(auto e:l) {
        cout << e;
    }
}