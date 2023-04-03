#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> num;
vector<char> op;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int tmp = 0;
    for(auto c:s) {
        if(c == '+' || c == '-') {
            op.push_back(c);
            num.push_back(tmp);
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += c - '0';
        }
    }
    num.push_back(tmp);

    int idx1 = 1;
    int idx2 = 0;
    int ans = num[0];
    while(idx1 < num.size()) {
        if(op[idx2] == '-') {
            do {
                ans -= num[idx1];
                idx1++;
                idx2++;
            }while(op[idx2] != '-' && idx2 < op.size());
        }

        else {
            ans += num[idx1];
            idx1++;
            idx2++;
        }

    }
    cout << ans;
}