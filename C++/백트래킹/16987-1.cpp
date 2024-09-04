#include <bits/stdc++.h>
using namespace std;
#define duration first
#define weight second
int n;
int cnt;
int ans;
bool isBroken[10];
vector<pair<int, int>> vec;

bool isEnd() {
    int count = 0;
    for(int i=0; i<n; i++) {
        if(!isBroken[i])
            count++;
    }
    if(count == 1)  return true;
    return false;
}

void func(int k) {
    if(k == n && isEnd() ) {
        ans = max(ans, cnt);
        fill(isBroken, isBroken+10, 0);
        return;
    }
    auto cur = vec[k];
    if(isBroken[k]) {
        func(k+1);
        return;
    }

    for(int i=0; i<n; i++) {
        if(k == i)  continue;
        if(!isBroken[i]) {
            cur.duration -= vec[i].weight;
            vec[i].duration -= cur.weight;
            if(vec[i].duration < 0) {
                isBroken[i] = true;
                cnt++;
            }
            if(cur.duration < 0)    {
                isBroken[k] = true;
                cnt++;
            }
            func(k+1);
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

