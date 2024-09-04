#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> s;
//    vector<char> ans;
    string ans;
    int idx = 1;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        while(idx <= a) {
            s.push(idx++);
//            ans.push_back('+');
            ans += "+\n";
        }
        if(s.top() == a) {
            s.pop();
//            ans.push_back('-');
            ans += "-\n";
        }
        else {
            cout << "NO";
            return 0;
        }
    }
//    for(auto it : ans)  cout << it << '\n';
    cout << ans;
}
