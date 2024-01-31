#include <bits/stdc++.h>
using namespace std;
int n;
int s[21][21];
bool start[21];
int mn = 100*10+1;

void comb(int k, int st) {

    if(k == n) { // 모두 start 팀일 경우 예외 처리
        return;
    }

    if(k != 0) { // 모두 link 팀일 경우 예외 처리
        int t1 = 0; // start 팀에 한명을 추가할 때 마다 능력치 차이 갱신
        int t2 = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(start[i] && start[j]) {
                    t1 += s[i][j];
                }
                else if(!start[i] && !start[j]) {
                    t2 += s[i][j];
                }
            }
        }
        mn = min(mn, abs(t1-t2));
    }

    for(int i=st; i<n; i++) {
        start[i] = true;
        comb(k+1, i+1);
        start[i] = false;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> s[i][j];
        }
    }
    comb(0, 0);
    cout << mn << '\n';
}