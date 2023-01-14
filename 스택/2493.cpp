#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];
    stack<int> s;
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << "0 ";
    for(int i=1; i<n; i++) {
        int tmp = arr[i];
        for(int j=0; j<i; j++) {
            s.push(arr[j]);
        }
        int idx=i;
        while(!s.empty()) {
//            cout << "test" << i << ' ' << idx << ' ' << s.top() << '\n';
            if(tmp < s.top()) {
                cout << idx << ' ';
                break;
            }
            else {
                s.pop();
                idx--;
            }
        }
        if(s.empty())   cout << "0 ";
    }
}
