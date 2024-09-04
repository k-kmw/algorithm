#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> vec(n);
    for(int i=0; i<n; i++)  cin >> vec[i];

    sort(vec.begin(), vec.end(), [](const string& a, const string & b) {
        if(a.length() != b.length())    return a.length() < b.length();
        return a < b;
    });
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for(auto & s: vec) {
        cout << s << '\n';
    }
}