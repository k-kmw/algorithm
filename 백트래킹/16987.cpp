#include <bits/stdc++.h>
using namespace std;
#define duration first
#define weight second
int n;
int cnt;
int ans;
bool isBroken[10];
vector<pair<int, int>> vec;
vector<pair<int, int>> vec2;

bool isEnd() {
    int count = 0;
    for(int i=0; i<n; i++) {
        if(!isBroken[i])
            count++;
    }
    if(count <= 1)  return true;
    return false;
}

void func(int k) {
    if(k == n || isEnd()) {
//        cout << "tst" << '\n';
//        for(int i=0; i<n; i++)
//            vec2[i] = vec[i];
//        fill(isBroken, isBroken+10, 0);
//        cout << cnt << '\n';
        ans = max(ans, cnt);
//        cnt = 0;
        return;
    }

    if(isBroken[k]) {
        func(k+1);
        return;
    }

    for(int i=0; i<n; i++) {
        if(k == i)  continue;
//        cout << i << ' ' << isBroken[i] << ' ';
        if(!isBroken[i]) {
            vec2[k].duration -= vec2[i].weight;
            vec2[i].duration -= vec2[k].weight;
            if(vec2[i].duration < 0) {
                cnt++;
                isBroken[i] = true;
            }
            if(vec2[k].duration < 0) {
                cnt++;
                isBroken[k] = true;
            }
//            cout << k << ' ' << i << ' ' << cnt << '\n';
            func(k+1);
            if(vec2[i].duration < 0) {
                cnt--;
            }
            if(vec2[k].duration < 0) {
                cnt--;
            }
            vec2[i].duration += vec2[k].weight;
            vec2[k].duration += vec2[i].weight;
            isBroken[i] = false;
            isBroken[k] = false;
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
        vec2.emplace_back(x, y);
    }
    func(0);
    cout << ans;
}

