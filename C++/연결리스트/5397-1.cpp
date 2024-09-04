#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        list<char> l = {};
        auto p = l.begin();
        string s;
        cin >> s;
        for(auto c:s) {
            if(c == '<') {
                if(p != l.begin())
                    p--;
            }
            else if(c == '>') {
                if(p != l.end())
                    p++;
            }
            else if(c == '-') {
                p--;
                p = l.erase(p);
            }
            else {
                l.insert(p, c);
            }
        }
        for(auto item: l) cout << item;
        cout << '\n';
    }

}