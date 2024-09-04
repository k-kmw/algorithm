#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    queue<int> q;
    int t, n;
    string op, arr;
    cin >> t;
    while(t--) {
        deque<int> dq;
        cin >> op >> n >> arr;
        int pos, cur = 1;
        bool isWrong = false;
        string result;
        bool direction = true;
        while((pos = arr.find(',', cur)) != string::npos) {
            int len = pos - cur;
            result = arr.substr(cur, len);
            dq.push_back(stoi(result));
            cur = pos + 1;
        }
        int end = arr.find(']', cur);
        result = arr.substr(cur, end-cur);
        if(end - cur > 0)
            dq.push_back(stoi(result));

        for(auto c: op) {
            if(c == 'R') {
                direction = !direction;
            }
            else {
                if(dq.empty()) {
                    isWrong = true;
                    cout << "error" << '\n';
                    break;
                }
                else {
                    if (direction) {
                        dq.pop_front();
                    }
                    else {
                        dq.pop_back();
                    }
                }
            }
        }
        if(!isWrong) {
            if (!direction) {
                reverse(dq.begin(), dq.end());
            }
            cout << '[';
            for (int i = 0; i < dq.size(); i++) {
                cout << dq[i];
                if(i+1 != dq.size())
                    cout << ',';
            }
            cout << "]\n";
        }

//        for(auto c: dq) cout << c << '\n';
    }

}