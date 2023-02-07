#include <bits/stdc++.h>
using namespace std;
#define duration first
#define weight second
int n;
int cnt;
bool broken[10];
bool isused[10];
vector<pair<int, int>> vec;
int arr[10];

void func(int k) {
    if(k == n) {
        cout << cnt;
        return;
    }
    for(int i=0; i<n; i++) {
        if(!isused[i]) {
            auto cur = vec[k];
            if(cur.duration < vec[i].weight) {
                cnt++;
            }


        }

    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }
    func(0);
//    for(int i=0; i<n; i++) {
//        cout << vec[i].first << ' ' << vec[i].second << '\n';
//    }
}

