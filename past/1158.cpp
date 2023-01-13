#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, k;
    cin >> n >> k;

    for(int i=1; i<n+1; i++)
        q.push(i);
    cout << "<";
    while(q.size() > 1) {
        for(int j=0; j<k-1; j++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">" << endl;
    q.pop();

    return 0;
}