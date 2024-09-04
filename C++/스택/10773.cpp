#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    cin >> k;

    stack<int> s;
    unsigned int total=0;
    while(k--) {
        int n;
        cin >> n;
        if(n == 0) {
            total -= s.top();
            s.pop();
        }
        else {
            total += n;
            s.push(n);
        }
    }
    cout << total;
}