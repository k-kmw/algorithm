#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<int> l;
    auto iter = l.begin();
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) l.insert(iter, i);
    for(int i=0; i<k; i++)  iter++;
    if(n == 1) {
        cout << '<' << *(iter) << '>';
        return 0;
    }
    else {
        cout << '<' << *(iter) << ", ";
    }
    iter = l.erase(iter);
    while(l.size()) {
        if(iter == l.end()) {
            iter = l.begin();
        }
        for(int i=0; i<k-1; i++){
            iter++;
            if(iter == l.end()) {
                iter = l.begin();
            }
        }
        if(l.size() == 1) {
            cout << *iter << '>';
            break;
        }
        cout << *iter << ", ";
        iter = l.erase(iter);
    }
}