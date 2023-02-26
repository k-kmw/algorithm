#include <bits/stdc++.h>
using namespace std;
vector<string> vec;

bool cmp(string a, string b) {
    if(a.length() != b.length())    return a.length() < b.length();
    return a < b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        bool dup = false;
        string s;
        cin >> s;
        for(auto & j : vec) {
            if (j == s) {
                dup = true;
                break;
            }
        }
        if(dup) {
            continue;
        }
        vec.push_back(s);
    }

    sort(vec.begin(), vec.end(), cmp);
    for(auto &v : vec) {
        cout << v << '\n';
    }
}