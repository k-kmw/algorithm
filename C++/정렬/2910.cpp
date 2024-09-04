#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> vec(n);

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        bool dup = false;
        for(auto & v : vec) {
            if(v.first == x) {
                v.second++;
                dup = true;
            }
        }
        if(!dup)    vec.emplace_back(x, 1);
    }
    stable_sort(vec.begin(), vec.end(), cmp);
    for(auto &v : vec) {
        while(v.second--) {
            cout << v.first << ' ';
        }
    }
}