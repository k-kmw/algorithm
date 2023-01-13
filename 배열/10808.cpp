#include <iostream>
#include <algorithm>
using namespace std;

int freq[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for(char c='a'; c<='z'; c++) {
        int cnt = 0;
        for(auto a : s) {
            if(a == c) {
                cnt++;
            }
        }
        cout << cnt << " ";
    }
}
