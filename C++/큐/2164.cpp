#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    while(!q.empty()) {
        if(q.size() == 1) {
            cout << q.front();
            break;
        }
        q.pop();
        q.push(q.front());
        q.pop();
    }
}