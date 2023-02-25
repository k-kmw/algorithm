#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
string s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> s;
        reverse(s.begin(), s.end());
        vec.push_back(stol(s));
    }
    sort(vec.begin(), vec.end());

    for(auto i : vec) {
        cout << i << '\n';
    }

}