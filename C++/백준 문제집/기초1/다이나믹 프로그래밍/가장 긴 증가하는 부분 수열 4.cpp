#include <bits/stdc++.h>
using namespace std;
int a[1001];
int d[1001];
vector<int> vec[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }

    d[n] = 1;
    vec[n].push_back(a[n]);
    for(int i=n-1; i>=1; i--) {
        for(int j=i+1; j<=n; j++) {
            if(a[i] < a[j]) {
                if(d[i] < d[j]) {
                    d[i] = d[j];
                    vec[i].clear();
                    for(auto v : vec[j]) {
                        vec[i].push_back(v);
                    }
                }
            }
        }
        vec[i].push_back(a[i]);
        d[i] += 1;
    }
    int mx = *max_element(d+1, d+n+1);
    cout << mx << '\n';
    for(int i=1; i<=n; i++) {
        if(vec[i].size() == mx) {
            sort(vec[i].begin(), vec[i].end());
            for(auto v : vec[i]) {
                cout << v << ' ';
            }
            break;
        }
    }
}