#include <bits/stdc++.h>
using namespace std;
int n;
int brokenCnt;
bool isBroken[11];
int ans;

bool hasBrokenNum(const string& s) {
    bool check = false;
    for (const auto &c: s) {
        if(isBroken[c-'0']) { // 현재 숫자에서 고장난 채널이 있으면
            check = true;
        }
    }
    return check;
}

void solve() {
    for(int i=n; i<=n+ans; i++) { // 위로 가장 가까운 수 찾기
        string s = to_string(i); // 숫자 길이를 활용하기 위해 문자열로 변환
        if(!hasBrokenNum(s)) {
            int tmp = s.size() + (i-n); // 숫자의 길이만큼 채널을 누르고, 나머지 차이만큼 +또는 -버튼
            ans = min(ans, tmp);
            break;
        }
    }
    for(int i=n; i>=0; i--) { // 아래로 가장 가까운 수 찾기
        string s = to_string(i);
        if(!hasBrokenNum(s)) {
            int tmp = s.size() + (n-i);
            ans = min(ans, tmp);
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> brokenCnt;
    for(int i=0; i<brokenCnt; i++) {
        int x;
        cin >> x;
        isBroken[x] = true;
    }
    ans = abs(n-100); // +/-로만 이동하는 경우
    solve();
    cout << ans;
}