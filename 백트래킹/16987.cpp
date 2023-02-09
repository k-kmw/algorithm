#include <bits/stdc++.h>
using namespace std;
#define duration first
#define weight second
int n;
int cnt;
int ans;
bool isBroken[10];
vector<pair<int, int>> vec;

void func(int k) {
    if(k == n) {
        ans = max(ans, cnt);
        return;
    }

    if(isBroken[k] || cnt == n-1) { // 현재 계란이 깨졌거나, 남은 계란이 하나이면 다음으로 진행
        func(k+1);
        return;
    }

    for(int i=0; i<n; i++) {
        if(i == k)  continue; // 자기 자신이면
        if(!isBroken[i]) { // 계란이 깨지지 않았으면
            vec[k].duration -= vec[i].weight;
            vec[i].duration -= vec[k].weight;
            if(vec[i].duration <= 0) { // i번째 계란이 깨지면
                cnt++;
                isBroken[i] = true;
            }
            if(vec[k].duration <= 0) { // 현재 계란이 깨지면
                cnt++;
                isBroken[k] = true;
            }
//            cout << k << ' ' << i << ' ' << cnt << '\n';
            func(k+1); // 다음으로 진행
            if(vec[i].duration <= 0) { // 아래부터는 과정이 진행된후 원래 상태로 돌려줌
                cnt--;
                isBroken[i] = false;
            }
            if(vec[k].duration <= 0) {
                cnt--;
                isBroken[k] = false;
            }
            vec[i].duration += vec[k].weight;
            vec[k].duration += vec[i].weight;
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
    cout << ans;
}
// 트리 한 번 더 그려보기