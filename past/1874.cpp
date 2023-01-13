#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    stack<int> s;
    int cnt = 1;
    int n;
    vector<char> v;
    cin >> n;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        while (cnt <= x) {
            s.push(cnt);
            v.emplace_back('+');
            cnt += 1;
        }
        if (s.top() == x)
        {
            v.emplace_back('-');
            s.pop();
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    for(const auto& item : v)
        cout << item << endl;
    return 0;
}